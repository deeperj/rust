//
// Face Picker Example
//
// The following code implements a "genetic algorithm" to
// learn a face.
// Genetic algorithms are usually used in machine learning,
// but can also be used to assist people.
//
// In this app, the goal is to find a face that you want.
// Imagine you need to describe a face to someone else and
// don't have a picture. Police sketch artists do this all
// the time.
//
// This app uses a genetic algorithm to help you narrow
// down or "refine" a vast selection of possible faces.
//
// On each screen, pick the faces that most closely match
// your desired face. Then tap "Refine". Keep doing this.
// The genetic algorithm will help you narrow down to the
// face that you want while also adding variations.
//
// Each time you "reproduce" the search, the genetic algorithm
// creates a new population by favoring your selection as
// parents and creating new children. These children become
// the new list of choices.
//
// Children are created by mutating their parents' genes.
// Mutation can either be:
// * Crossover when a gene is selected from either parent
// * Uniform mutation when a gene takes on any possible value
// * Blend mutation when a gene blends its parents' values
//
// Experiments:
// 1. Change the number of faces shown at a time
// 2. Change the range of allowed face gene values to see
//    even more variations.
// 3. Add another facial gene and add more features to the
//    face (eyebrows, nose, ears, hair, ...)
// 4. Switch to picking colors (BONUS code near the bottom)
// 5. Create your own genetic object with your own genes.
// 6. Add a share feature to send your an image of the selected
//    face.
//

using System;
using System.Collections.Generic;
using System.Linq;

using UIKit;
using CoreGraphics;

class Gene {
    public readonly string Name;
    public readonly double MinValue;
    public readonly double MaxValue;
    public readonly double Value;
    
    public Gene (string name, double minVal, double maxVal, double val) {
        Name = name;
        MinValue = minVal;
        MaxValue = maxVal;
        Value = val;
    }
    
    public Gene WithValue (double val) => new Gene(Name, MinValue, MaxValue, val);
    
    public static Gene Random (string name, double minVal, double maxVal, Random rand) =>
        new Gene(name, minVal, maxVal, rand.NextDouble()*(maxVal-minVal) + minVal);
}

class GeneticOptions {    
    public readonly Random Rand = new Random(DateTime.Now.Minute);
    public double CrossoverProbability = 0.125;
    public double UniformMutationProbability = 0.75;
    public double BlendMutationProbability = 0.25;
    public bool ShouldCrossover() => Rand.NextDouble() < CrossoverProbability;
    public bool ShouldUniformMutate() => Rand.NextDouble() < UniformMutationProbability;
    public bool ShouldBlendMutate() => Rand.NextDouble() < BlendMutationProbability;
    public Action<GeneticObject, CGContext, CGRect> DrawObject = (o,c,r) => {};
    public Func<int, List<GeneticObject>> MakePopulation = n =>
        Enumerable.Range(0,n).Select(_ => new GeneticObject()).ToList();
}

class GeneticObject {
    public readonly Dictionary<string, Gene> Genes = new Dictionary<string, Gene>();
    
    public void AddGene(Gene g) => Genes.Add(g.Name, g);
    
    public static GeneticObject Reproduce(List<GeneticObject> parents, GeneticOptions options)
    {        
        // Pick a main parent for mutation
        var maini = options.Rand.Next(parents.Count);
        var mainp = parents[maini];
        
        var child = new GeneticObject();
        foreach (var x in mainp.Genes) {            
            var name = x.Key;
            var g = x.Value;
            if (options.ShouldCrossover()) {
                var crossi = options.Rand.Next(parents.Count);
                child.AddGene (parents[crossi].Genes[name]);
            }
            else if (options.ShouldBlendMutate()) {
                var blend = parents.Average(p => p.Genes[name].Value);
                child.AddGene (g.WithValue(blend));
            }
            else if (options.ShouldUniformMutate()) {
                var uniform = options.Rand.NextDouble() * (g.MaxValue-g.MinValue) + g.MinValue;
                child.AddGene (g.WithValue(0.25 * uniform + 0.75 * g.Value));
            }
            else {
                child.AddGene (g);
            }
        }
        
        return child;
    }
}


//
// The following code creates a UI for controlling the
// genetic algorithm.
//
// This UI is generic - any kind of GeneticObject
// can be used.
//

class GeneticObjectView : UIView {
    
    readonly GeneticOptions options;
    GeneticObject gobject = new GeneticObject();
    bool selected = false;
    
    class SelView : UIView {        
        public SelView() {
            BackgroundColor = UIColor.Clear;
        }
        public override void Draw (CGRect d) {
            var c = UIGraphics.GetCurrentContext();
            var b = Bounds;
            b.Inflate(-10, -10);
            c.SetStrokeColor(0, 0.75f);
            c.SetLineWidth(11);
            c.StrokeRect(b);
        }
    }
    
    UIView selView = new SelView() {
        UserInteractionEnabled = false,
    };
    
    public bool Selected => selected;
    public GeneticObject GeneticObject => gobject;
    
    public GeneticObjectView(GeneticOptions options) : base(new CGRect(0,0,44,44)) {
        this.options = options;
        ContentMode = UIViewContentMode.Redraw;
        UserInteractionEnabled = true;
        BackgroundColor = UIColor.White;
        selView.Frame = Bounds;
        selView.Alpha = 0;
        selView.AutoresizingMask = UIViewAutoresizing.FlexibleDimensions;
        AddSubview (selView);
        
        var tapGesture = new UITapGestureRecognizer(this.OnTap);
        AddGestureRecognizer(tapGesture);
    }
    
    void OnTap (UITapGestureRecognizer g) {
        selected = !selected;
        UIView.Animate(0.125, () => selView.Alpha = selected ? 1 : 0, null);
    }
    
    public void SetGeneticObject (GeneticObject gobj) {
        gobject = gobj;
        selected = false;
        selView.Alpha = 0;
        SetNeedsDisplay();
    }
    
    public override void Draw(CGRect rect) {
        BackgroundColor.SetFill();
        UIGraphics.RectFill(rect);
        var ctx = UIGraphics.GetCurrentContext();
        options.DrawObject(gobject, ctx, Bounds);
    }
}

class PopulationController : UIViewController {
    
    readonly GeneticOptions options;
    
    int populationSize = 0;
    int numRows = 0;
    List<GeneticObject> population = new List<GeneticObject>();
    GeneticObjectView[] objectViews = new GeneticObjectView[0];
    
    public PopulationController(GeneticOptions options) {
        this.options = options;
        populationSize = 16;
        numRows = 4;
        objectViews =
            Enumerable.Range(0,populationSize)
            .Select(_ => new GeneticObjectView(options))
            .ToArray();
            
        NavigationItem.RightBarButtonItem =
            new UIBarButtonItem("Reproduce", UIBarButtonItemStyle.Plain, (s,e) => {
                ReproducePopulation();
            });
            
        NavigationItem.LeftBarButtonItem =
            new UIBarButtonItem("Start Over", UIBarButtonItemStyle.Plain, (s,e) => {
                RefreshPopulation();
            });
    }
    
    public override void ViewDidLoad() {        
        base.ViewDidLoad();
        View.AddSubviews(objectViews);
        LayoutObjectViews();
        RefreshPopulation();
    }
    
    void LayoutObjectViews() {        
        if (populationSize == 0 || numRows == 0) return;
        // Determine the size of each view
        var numCols = populationSize / numRows;
        var cw = (nfloat)(Math.Round(View.Bounds.Width / numCols));
        var rh = (nfloat)(Math.Round(View.Bounds.Height / numRows));
        // Position them in a grid
        var ri = 0;
        var ci = 0;
        foreach (var v in objectViews) {            
            v.Frame = new CGRect (ci*cw, ri*rh, cw, rh);
            ci++;
            if (ci >= numCols) {
                ri++;
                ci = 0;
            }
        }
    }
    
    public override void ViewDidLayoutSubviews() {
        base.ViewDidLayoutSubviews();
        LayoutObjectViews();
    }
    
    void DisplayPopulation() {
        foreach (var i in Enumerable.Range(0, populationSize)) {
            objectViews[i].SetGeneticObject(population[i]);
        }        
    }
    
    void RefreshPopulation() {
        population = options.MakePopulation(populationSize);
        DisplayPopulation();        
    }
    
    void ReproducePopulation() {
        var selected =
            objectViews
            .Where(x => x.Selected)
            .ToList();
        if (selected.Count == 0) {
            var alert = UIAlertController.Create(
                "Cannot Reproduce", "Select some of the population to reproduce.", UIAlertControllerStyle.Alert);
            alert.AddAction(UIAlertAction.Create("OK", UIAlertActionStyle.Cancel, (e)=>{}));
            PresentViewController(alert, true, null);
            return;
        }
        
        Func<GeneticObject> getParent = () => {
            return selected[options.Rand.Next(selected.Count)].GeneticObject;
        };
        
        var newPopulation =
            Enumerable.Range(0, populationSize)
            .Select(i => {
                var parents = new List<GeneticObject>();
                parents.Add(getParent());
                parents.Add(getParent());
                return GeneticObject.Reproduce(parents, options);
            });
        
        population = newPopulation.ToList();
        DisplayPopulation();
    }
}


//
// Now that we have a generic picker, let's specialize
// it for selecting faces.
//
// We will have to write a bunch of code to draw faces.
//

class MirroredDrawer {
    CGContext ctx;
    public MirroredDrawer(CGContext ctx) {
        this.ctx = ctx;
    }
    public void DrawLine (double sx, double sy, double ex, double ey) {
        ctx.MoveTo((nfloat)sx, (nfloat)sy);
        ctx.AddLineToPoint((nfloat)ex, (nfloat)ey);
        ctx.MoveTo((nfloat)(-sx), (nfloat)sy);
        ctx.AddLineToPoint((nfloat)(-ex), (nfloat)ey);
        ctx.StrokePath();
    }
}
class MirroredPath {
    public readonly CGPath Path = new CGPath();
    List<Tuple<CGPoint,CGPoint,CGPoint,CGPoint>> curves =
        new List<Tuple<CGPoint,CGPoint,CGPoint,CGPoint>>();
    CGPoint pos = CGPoint.Empty;
    bool closed = false;
    public void MoveTo(CGPoint p) {
        pos = p;
    }
    public void CurveTo(CGPoint c1, CGPoint c2, CGPoint p) {
        curves.Add(Tuple.Create(pos, c1, c2, p));
        pos = p;
    }
    public void Close() { closed = true; }
    public void Stroke(CGContext ctx) {
        if (curves.Count == 0) return;
        var moveTo = curves[0].Item1;
    
        Path.MoveToPoint(moveTo.X, moveTo.Y);
        foreach (var c in curves) {
            Path.AddCurveToPoint(c.Item2, c.Item3, c.Item4);
        }
        foreach (var c in Enumerable.Reverse(curves)) {            
            var c1 = new CGPoint (-c.Item3.X, c.Item3.Y);
            var c2 = new CGPoint (-c.Item2.X, c.Item2.Y);
            var ep = new CGPoint (-c.Item1.X, c.Item1.Y);
            Path.AddCurveToPoint(c1, c2, ep);
        }
        if (closed) {
            Path.CloseSubpath();
        }
        ctx.AddPath(Path);
        ctx.StrokePath();
    }
}

void DrawFace (GeneticObject face, CGContext ctx, CGRect bounds) {
    var ppmm = (float)bounds.Height / 340;
    
    ctx.SetLineJoin(CGLineJoin.Round);
    ctx.SetStrokeColor(0.0f, 1.0f);
    ctx.SetFillColor(0.0f, 1.0f);
    
    ctx.TranslateCTM(bounds.Width/2, bounds.Height/2);
    ctx.ScaleCTM(ppmm, -ppmm);
    
    var mirror = new MirroredDrawer (ctx);
    
    var faceHeight = face.Genes["FaceHeight"].Value;    
    var mentonToSellionP = face.Genes["MentonToSellionPHeight"].Value;
    var mentonToSellion = mentonToSellionP * faceHeight;
    var mentonToStomionP = face.Genes["MentonToStomionPSellion"].Value;
    var mentonToStomion = mentonToSellion * mentonToStomionP;
    var sellionToTop = faceHeight - mentonToSellion;
    var stomionToTop = faceHeight - mentonToStomion;
    var bitragionBreadth = face.Genes["BitragionBreadth"].Value;
    var mouthWidth = face.Genes["MouthBreadth"].Value;
    var chinWidth = face.Genes["ChinBreadth"].Value;
        
    var eyeWidth = face.Genes["EyeWidth"].Value;
    var eyeHeight = face.Genes["EyeHeight"].Value;
    var eyeAngle = face.Genes["EyeAngle"].Value;
    var pupilWidth = 10.0;
    
    var smile = face.Genes["Smile"].Value;
    
    var headBottom = -mentonToSellion;
    var headTop = sellionToTop;
    var mouthY = headTop - stomionToTop;
    var headWidth = bitragionBreadth;
    
    // Draw the head
    var h = new MirroredPath();
    h.MoveTo(new CGPoint(0, headTop));
    h.CurveTo(new CGPoint(-headWidth/2, headTop),
              new CGPoint(-headWidth/2, headTop*0.25),
              new CGPoint(-headWidth/2, 0));
    h.CurveTo(new CGPoint(-headWidth/2, headBottom*0.85),
              new CGPoint(-chinWidth/2, headBottom*0.98),
              new CGPoint(-chinWidth/2, headBottom*0.99));
    h.CurveTo(new CGPoint(-chinWidth/4, headBottom*1.0),
              new CGPoint(-chinWidth/4, headBottom*1.0),
              new CGPoint(0, headBottom));
    h.Close();
    h.Stroke(ctx);
    
    // Draw the eyes
    var e = new CGPath();
    var pupilRect = new CGRect((nfloat)(-pupilWidth/2), (nfloat)(-pupilWidth/2), (nfloat)(pupilWidth), (nfloat)(pupilWidth));
    e.MoveToPoint((nfloat)(-eyeWidth/2), 0);
    e.AddCurveToPoint((nfloat)(-eyeWidth*0.3), (nfloat)(eyeHeight*1.25),
                      (nfloat)(eyeWidth*0.3), (nfloat)(eyeHeight*0.99),
                      (nfloat)(eyeWidth*0.5), (nfloat)(0));
    e.AddCurveToPoint((nfloat)(eyeWidth*0.4), (nfloat)(eyeHeight*0.2),
                      (nfloat)(-eyeWidth*0.1), (nfloat)(-eyeHeight*1.25),
                      (nfloat)(-eyeWidth*0.5), (nfloat)(0));
    ctx.SaveState();
    ctx.TranslateCTM((nfloat)(-mouthWidth/2), 0);
    ctx.RotateCTM((nfloat)eyeAngle);
    ctx.AddPath(e);
    ctx.SaveState();
    ctx.Clip();
    ctx.FillEllipseInRect(pupilRect);
    ctx.RestoreState();
    ctx.AddPath(e);
    ctx.StrokePath();
    ctx.RestoreState();    
    ctx.SaveState();    
    ctx.TranslateCTM((nfloat)mouthWidth/2, 0);
    ctx.RotateCTM(-(nfloat)eyeAngle);
    ctx.ScaleCTM(-1, 1);
    ctx.AddPath(e);
    ctx.SaveState();
    ctx.Clip();
    ctx.FillEllipseInRect(pupilRect);
    ctx.RestoreState();
    ctx.AddPath(e);
    ctx.StrokePath();
    ctx.RestoreState();    
    
    // Draw the mouth
    var m = new CGPath();
    m.MoveToPoint((nfloat)(-mouthWidth/2), (nfloat)(mouthY - smile));
    m.AddCurveToPoint((nfloat)(-mouthWidth*0.3), (nfloat)(mouthY + smile),
                      (nfloat)(mouthWidth*0.3), (nfloat)(mouthY + smile),
                      (nfloat)(mouthWidth/2), (nfloat)(mouthY - smile));
    ctx.AddPath(m);
    ctx.StrokePath();
}

GeneticObject CreateRandomFace (GeneticOptions options) {
    var face = new GeneticObject();
    // Head proportions
    face.AddGene(Gene.Random("FaceHeight", 191, 266, options.Rand));
    face.AddGene(Gene.Random("MentonToSellionPHeight", 0.45, 0.65, options.Rand));
    face.AddGene(Gene.Random("MentonToStomionPSellion", 0.4, 0.6, options.Rand));
    face.AddGene(Gene.Random("BitragionBreadth", 125, 159, options.Rand));
    face.AddGene(Gene.Random("MouthBreadth", 55, 74, options.Rand));
    face.AddGene(Gene.Random("ChinBreadth", 22, 33, options.Rand));
    // Features
    face.AddGene(Gene.Random("EyeHeight", 3, 30, options.Rand));
    face.AddGene(Gene.Random("EyeWidth", 20, 50, options.Rand));
    face.AddGene(Gene.Random("EyeAngle", -0.333, 0.333, options.Rand));
    face.AddGene(Gene.Random("Smile", -15, 15, options.Rand));
    return face;
}


//
// Now that we can draw faces, let's configure the
// PopulationController to:
// 1. Create new starting populations of random faces
// 2. Tell it how to draw faces
//

PopulationController MakeFaceController () {
    
    var options = new GeneticOptions();
    options.DrawObject = DrawFace;
    
    options.MakePopulation = n =>        
        Enumerable.Range(0, n)
        .Select(_ => CreateRandomFace(options))
        .ToList();
    
    return new PopulationController(options);
}


//
// BONUS: Instead of picking faces, you can pick colors!
//

GeneticObject CreateRandomColor (GeneticOptions options) {
    var o = new GeneticObject();
    o.AddGene(Gene.Random("R", 0, 1, options.Rand));
    o.AddGene(Gene.Random("G", 0, 1, options.Rand));
    o.AddGene(Gene.Random("B", 0, 1, options.Rand));
    return o;
}

void DrawColor (GeneticObject face, CGContext ctx, CGRect bounds) {
    var r = face.Genes["R"].Value;
    var g = face.Genes["G"].Value;
    var b = face.Genes["B"].Value;
    ctx.SetFillColor((nfloat)r, (nfloat)g, (nfloat)b, 1);
    ctx.FillRect(bounds);
}

PopulationController MakeColorController () {
    
    var options = new GeneticOptions();
    options.DrawObject = DrawColor;    
    options.MakePopulation = n =>        
        Enumerable.Range(0, n)
        .Select(_ => CreateRandomColor(options))
        .ToList();
    
    return new PopulationController(options);
}


//
// Create a Main object to present the UI
//
var Main = new UINavigationController(MakeFaceController());






