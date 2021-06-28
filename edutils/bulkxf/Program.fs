open System
open System.Diagnostics
open System.Windows
// open System.Windows.Controls
// open ui

//[<STAThread>]
//do RunApp() |> ignore
Debug.WriteLine "hello world"
System.Windows.Forms.Clipboard.SetText  "hello world"
 
(*
Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
dlg.FileName = "Document"; // Default file name
dlg.DefaultExt = ".txt"; // Default file extension
dlg.Filter = "Text documents (.txt)|*.txt"; // Filter files by extension

// Show open file dialog box
Nullable<bool> result = dlg.ShowDialog();

let removeAt index list =
    list |> List.indexed |> List.filter (fun (i, _) -> i <> index) |> List.map snd

// Process open file dialog box results
if (result == true)
{
    // Open document
    string filename = dlg.FileName;
}
type Student(name, studentID : int) =
   inherit Person(name)
   let mutable _GPA = 0.0
   member x.StudentID = studentID
   member x.GPA
      with get() = _GPA
      and set value = _GPA <- value
*)