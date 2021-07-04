#r @"C:\Program Files\dotnet\packs\Microsoft.WindowsDesktop.App.Ref\3.1.0\ref\netcoreapp3.1\System.Windows.Forms.dll"
#r "System.Drawing.dll"

open System
open System.Drawing
open System.Windows.Forms

let exercise = new Form(MaximizeBox = true, Text = "Exercise")

let exercisePaint(e : PaintEventArgs) =
  let pnBorder : Pen = new Pen(Color.Red) 
  return None;

exercise.Paint.Add exercisePaint
do Application.Run exercise