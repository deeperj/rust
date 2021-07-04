open System
open System.Windows.Forms
open System.Drawing
open System.Drawing.Drawing2D

let exercise = new Form(MaximizeBox = true)

let exercisePaint(e : PaintEventArgs) =
    let pnBorder : Pen = new Pen(Color.Brown);
    // Do something, if necessary
    pnBorder.Width <- 6.00F
    // Do something, if necessary
    pnBorder.Width <- 12.00F
    // Do something, if necessary
    pnBorder.Width <- 26.00F
    // Do something, if necessary
    pnBorder.Width <- 44.00F
    // Do something, if necessary
    pnBorder.Width <- 3.00F

    let point1 = new PointF(100.0F, 100.0F)
    let point2 = new PointF(250.0F, 100.0F)
             
    // Draw line to screen.
    e.Graphics.DrawLine(pnBorder, point1, point2)

exercise.Paint.Add exercisePaint
do Application.Run exercise

// let form = new Form(Text="F# Windows Form",
//                     Visible = true,
//                     TopMost = true)

// form.Click.Add(fun evArgs -> System.Console.Beep())

// [<STAThread>]
// do Application.Run(form)

