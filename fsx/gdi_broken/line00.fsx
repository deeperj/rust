// #r @"C:\Program Files\dotnet\shared\Microsoft.WindowsDesktop.App\3.1.8\System.Drawing.dll" C:\Program Files\dotnet\packs\Microsoft.NETCore.App.Ref\3.1.0\ref\netcoreapp3.1
#r @"C:\Users\User\bin\GodotSharp\Mono\lib\mono\4.5\System.Drawing.dll"
#r @"C:\Program Files\dotnet\packs\Microsoft.WindowsDesktop.App.Ref\3.1.0\ref\netcoreapp3.1\System.Windows.Forms.dll"
//#r "System.Drawing.dll"

open System
open System.Drawing
open System.Windows.Forms

let exercise = new Form(MaximizeBox = true, Text = "Exercise")

let exercisePaint(e : PaintEventArgs) =
  let clr : Color = Color.Violet
  let pnBorder : Pen = new Pen(clr)
  return None;

exercise.Paint.Add exercisePaint
do Application.Run exercise

