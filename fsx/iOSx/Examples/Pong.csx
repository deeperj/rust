//
// Pong Example
//
// Implements a basic version of the classic game for two players.
// Swipe up and down on the left to move the left paddle, and
// swipe on the right side for the right paddle.
//
// Tip: If the editor freezes while you type,
//      turn off "Auto Run" in the settings.
//
// Exercises:
// 1. Change the color of the ball to green
// 2. Change the size of the paddles
// 3. Make the ball move faster
// 4. Add multiple balls
// 5. Add an AI to control the second paddle
//

using System;

using CoreGraphics;
using SceneKit;
using UIKit;

static class PongDefaults
{
    public static float BallSize = 5.0f;
    public static UIColor BallColor = UIColor.Yellow;
    public static float BallRestitution = 2.01f;
    public static float LeftPaddleHeight = 30.0f;
    public static float RightPaddleHeight = 30.0f;
}

class Ball {
    public readonly SCNNode Node;
    public Ball() {
        var geom = SCNSphere.Create(PongDefaults.BallSize);
        geom.FirstMaterial.Diffuse.ContentColor = PongDefaults.BallColor;
        Node = SCNNode.FromGeometry(geom);

        // Attach a light to the ball
        var ln = SCNNode.Create();
        ln.Light = SCNLight.Create();
        ln.Position = new SCNVector3(0,0,PongDefaults.BallSize*4);
        Node.Add(ln);

        // Add physics to the ball
        Node.PhysicsBody = SCNPhysicsBody.CreateDynamicBody();
        Node.PhysicsBody.Damping = 0;
        Node.PhysicsBody.Friction = 0;
        Node.PhysicsBody.Restitution = PongDefaults.BallRestitution;
        var options = new SCNPhysicsShapeOptions();
        Node.PhysicsBody.PhysicsShape = SCNPhysicsShape.Create(geom, options);
        Node.PhysicsBody.CategoryBitMask = 1u;
        Node.PhysicsBody.CollisionBitMask = 1u;
        Node.PhysicsBody.ContactTestBitMask = 1u;
    }
}

class Paddle {
    public readonly SCNNode Node;
    public Paddle(float x, float h) {
        var geom = SCNBox.Create(4, h, 20, 0);
        geom.FirstMaterial.Diffuse.ContentColor = UIColor.LightGray;
        geom.FirstMaterial.Specular.ContentColor = UIColor.Yellow;
        geom.FirstMaterial.Specular.Intensity = 1;
        Node = SCNNode.FromGeometry(geom);
        Node.Position = new SCNVector3(x,0,0);
        Node.PhysicsBody = SCNPhysicsBody.CreateStaticBody();
        var options = new SCNPhysicsShapeOptions();
        Node.PhysicsBody.PhysicsShape = SCNPhysicsShape.Create(geom, options);
        Node.PhysicsBody.CategoryBitMask = 1u;
        Node.PhysicsBody.CollisionBitMask = 1u;
        Node.PhysicsBody.ContactTestBitMask = 1u;
    }
}

class Wall {
    public readonly SCNNode Node;
    public Wall(float y) {
        var geom = SCNBox.Create(200, 4, 15, 0);
        geom.FirstMaterial.Diffuse.ContentColor = UIColor.DarkGray;
        geom.FirstMaterial.Specular.ContentColor = UIColor.Yellow;
        geom.FirstMaterial.Specular.Intensity = 1;
        Node = SCNNode.FromGeometry(geom);
        Node.Position = new SCNVector3(0,y,0);
        Node.PhysicsBody = SCNPhysicsBody.CreateStaticBody();
        var options = new SCNPhysicsShapeOptions();
        Node.PhysicsBody.PhysicsShape = SCNPhysicsShape.Create(geom, options);
        Node.PhysicsBody.CategoryBitMask = 1u;
        Node.PhysicsBody.CollisionBitMask = 1u;
        Node.PhysicsBody.ContactTestBitMask = 1u;
    }
}

class Goal {
    public readonly SCNNode Node;
    public Goal(float x) {
        var geom = SCNBox.Create(6, 400, 20, 0);
        geom.FirstMaterial.Diffuse.ContentColor = UIColor.Black;
        Node = SCNNode.FromGeometry(geom);
        Node.Position = new SCNVector3(x,0,0);
        Node.PhysicsBody = SCNPhysicsBody.CreateKinematicBody();
        var options = new SCNPhysicsShapeOptions();
        Node.PhysicsBody.PhysicsShape = SCNPhysicsShape.Create(geom, options);
        Node.PhysicsBody.CategoryBitMask = 1u;
        Node.PhysicsBody.CollisionBitMask = 1u;
        Node.PhysicsBody.ContactTestBitMask = 1u;
    }
}

class Camera {
    public readonly SCNNode Node = SCNNode.Create();
    readonly SCNCamera camera = SCNCamera.Create();
    public Camera() {
        Node.Camera = camera;
        Node.Position = new SCNVector3 (0,0,150);
        camera.ZNear = 1;
        camera.ZFar = 150;
        // Attach a light to the camera
        var ln = SCNNode.Create();
        ln.Light = SCNLight.Create();
        ln.Position = new SCNVector3(0,0,50);
        Node.Add(ln);
    }
}

//
// Create the game
//
var playerScore = 0;
var aiScore = 0;
var cam = new Camera();
var ball = new Ball();
var playerPaddle = new Paddle(-90, PongDefaults.LeftPaddleHeight);
var aiPaddle = new Paddle(90, PongDefaults.RightPaddleHeight);
var topWall = new Wall(70);
var botWall = new Wall(-70);
var playerGoal = new Goal(-130);
var aiGoal = new Goal(130);

//
// Create the view
//
var scene = SCNScene.Create();
scene.PhysicsWorld.Gravity = SCNVector3.Zero;
var root = scene.RootNode;

var scoreLabel = new UILabel() {
    Text = "0 : 0",
    TextAlignment = UITextAlignment.Center,
    Font = UIFont.SystemFontOfSize(100),
    TextColor = UIColor.White.ColorWithAlpha(0.25f),
    AutoresizingMask = UIViewAutoresizing.FlexibleDimensions,
    AdjustsFontSizeToFitWidth = true,
};
void UpdateScore() {
    
    scoreLabel.BeginInvokeOnMainThread(() => {
        scoreLabel.Text = $"{playerScore} : {aiScore}";
    });
}
var sceneView = new SCNView(new CGRect(0,0,320,320));
sceneView.BackgroundColor = UIColor.Black;
sceneView.Scene = scene;
scoreLabel.Frame = sceneView.Bounds;
sceneView.AddSubview(scoreLabel);

root.Add(cam.Node);
root.Add(ball.Node);
root.Add(playerPaddle.Node);
root.Add(aiPaddle.Node);
root.Add(topWall.Node);
root.Add(botWall.Node);
root.Add(playerGoal.Node);
root.Add(aiGoal.Node);
sceneView.PointOfView = cam.Node;

var rand = new Random();

void ResetBallPosition (float x) {
    
    var vx = ((float)rand.NextDouble()) * 75 + 75;
    var vy = ((float)rand.NextDouble()) * 50 + 50;
    if (x > 0) vx *= -1.0f;
    if (rand.Next(2) == 0) vy *= -1.0f;
    ball.Node.Position = new SCNVector3(x, 0, 0);
    ball.Node.PhysicsBody.Velocity = new SCNVector3(vx, vy, 0);
    ball.Node.PhysicsBody.ResetTransform();
}

ResetBallPosition(0);

scene.PhysicsWorld.DidBeginContact += (s,e) => {
    
    var otherNode = e.Contact.NodeA == ball.Node ? e.Contact.NodeB :
        (e.Contact.NodeB == ball.Node ? e.Contact.NodeA : null);
    if (otherNode == playerGoal.Node) {
        //Console.WriteLine("HIT PLAYER");
        aiScore++;
        ResetBallPosition(50);
        UpdateScore();
    }
    else if (otherNode == aiGoal.Node) {
        //Console.WriteLine("HIT AI");
        playerScore++;
        ResetBallPosition(-50);
        UpdateScore();
    }
//    e.Contact.NodeA.Geometry.FirstMaterial.Diffuse.ContentColor=UIColor.Red;
};
var panGesture = new UIPanGestureRecognizer (g => {
    for (var i = 0; i < g.NumberOfTouches; i++) {
        var viewLoc = g.LocationOfTouch(i, sceneView);
        var pos = sceneView.UnprojectPoint(new SCNVector3((float)viewLoc.X, (float)viewLoc.Y, 0.5f));
        if (pos.X < 0) {
            playerPaddle.Node.Position = new SCNVector3(-90, pos.Y, 0.0f);
            playerPaddle.Node.PhysicsBody.ResetTransform();
        }
        else {
            aiPaddle.Node.Position = new SCNVector3(90, pos.Y, 0.0f);
            aiPaddle.Node.PhysicsBody.ResetTransform();        
        }
    }
});
var tapGesture = new UITapGestureRecognizer (g => {
    ResetBallPosition (0);
});
tapGesture.NumberOfTapsRequired = 2;
sceneView.AddGestureRecognizer(panGesture);
sceneView.AddGestureRecognizer(tapGesture);

var Main = sceneView;














