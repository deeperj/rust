//
// Sketch Example
//
// A very simple drawing app that demonstrates custom drawing
// with UIViews, UIGestureRecognizers, and sharing.
//
// 1. Change the color of drawn lines
//
// 1. Add a color selector
// 2. Add the most recent message at the top
//

using System;
using System.Collections.Generic;
using System.Linq;

using CoreGraphics;
using Foundation;
using UIKit;

// Default values used by the app
static class SketchDefaults {
    public static UIColor StrokeColor = UIColor.LabelColor;
    public static nfloat StrokeWidth = 4.0f;
    public static UIColor BackgroundColor = UIColor.SystemBackgroundColor;
}

// A stroke is a recording of the points visited by a person's
// finger as they pan across the screen.
// A stroke also contains color and line width info just incase
// you want to turn this into a proper drawing app.
class Stroke {
    public readonly List<CGPoint> Points = new List<CGPoint> ();
    public UIColor Color = SketchDefaults.StrokeColor;
    public nfloat Width = SketchDefaults.StrokeWidth;
}

// A document records the list of strokes.
// The document class is where you would add reading and writing files
// to your app.
class Document {    
    public readonly List<Stroke> Strokes = new List<Stroke> ();
}

// A custom UIView that can draw strokes.
class DocumentView : UIView {
    readonly Document doc;
    public DocumentView(Document doc) {
        this.doc = doc;
        BackgroundColor = SketchDefaults.BackgroundColor;
        ContentMode = UIViewContentMode.Redraw;
    }
    public override void Draw(CGRect rect) {        
        BackgroundColor.SetFill();
        UIGraphics.RectFill(rect);

        var context = UIGraphics.GetCurrentContext();
        
        foreach (var s in doc.Strokes) {
            s.Color.SetStroke();
            context.SetLineWidth(s.Width);
            if (s.Points.Count > 1) {
                context.MoveTo(s.Points[0].X, s.Points[0].Y);
                foreach (var p in s.Points.Skip(1)) {
                    context.AddLineToPoint(p.X, p.Y);
                }
            }
            context.StrokePath();
        }
    }
}

// An object that combines a document and a view
// to create an interactive editing experience.
class DocumentController : UIViewController {
    
    readonly Document doc = new Document();
    readonly DocumentView docView;
    
    public Document Document => doc;
    
    public DocumentController () {
        
        Title = "Sketch!";
        
        // Create a view that can draw our sketch
        docView = new DocumentView(doc);
        
        // Create a gesture recognizer to draw sketches
        var panGesture = new UIPanGestureRecognizer (g => {
            // Get the current pan location
            var loc = g.LocationInView(docView);
            
            // When the gesture is just beginning,
            // we create a new stroke.
            // When the user pans, the gesture changes, and
            // we add that point to the last stroke.
            if (g.State == UIGestureRecognizerState.Began) {
                var stroke = new Stroke ();
                stroke.Points.Add(loc);
                doc.Strokes.Add(stroke);
            }
            else if (g.State == UIGestureRecognizerState.Changed) {
                var stroke = doc.Strokes.LastOrDefault();
                if (stroke != null) {
                    stroke.Points.Add(loc);
                    docView.SetNeedsDisplay();
                }
            }
        });        
        docView.AddGestureRecognizer (panGesture);
        
        // Add a clear button
        NavigationItem.LeftBarButtonItem =
            new UIBarButtonItem("Clear", UIBarButtonItemStyle.Plain, (s, e) => {
                doc.Strokes.Clear();
                docView.SetNeedsDisplay();
            });
            
        // Add a share button
        NavigationItem.RightBarButtonItem =
            new UIBarButtonItem(UIBarButtonSystemItem.Action, (s, e) => {
                // Draw the view into a UIImage
                UIGraphics.BeginImageContext(docView.Frame.Size);
                docView.DrawViewHierarchy(docView.Bounds, false);
                var image = UIGraphics.GetImageFromCurrentImageContext();
                UIGraphics.EndImageContext();
                
                // Share that image
                var items = new NSObject[] { image };
                var action = new UIActivityViewController(items, null);
                action.PopoverPresentationController.BarButtonItem = NavigationItem.RightBarButtonItem;
                PresentViewController(action, true, null);
                
            });
        
        // Use the document view as the root view for this controller
        View = docView;
    }
}


var Main = new UINavigationController(new DocumentController());










