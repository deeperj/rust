open System
open System.Windows
open System.Windows.Controls
open FD

let a = Application()

let w = Window()
w.SizeToContent <- SizeToContent.WidthAndHeight

let sp = StackPanel()

let t = TextBlock()
t.Text <- "hello world"

let dp1 = DatePicker()

sp.Children.Add t |> ignore

let b = Button()
b.Content <- "Click Me"

dp1.SelectedDateChanged.AddHandler(fun s ea -> 
  do
    let span = dp1.SelectedDate.Value.Subtract( DateTime.Now)/365.2525
    t.Text <- span.TotalDays.ToString()
)

b.Click.AddHandler(fun s ea -> 
  let st=openFD()
  t.Text <- st
)
sp.Children.Add b |> ignore

sp.Children.Add dp1 |> ignore
w.Content <- sp

[<STAThread>]
do a.Run(w) |> ignore


(*
Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
dlg.FileName = "Document"; // Default file name
dlg.DefaultExt = ".txt"; // Default file extension
dlg.Filter = "Text documents (.txt)|*.txt"; // Filter files by extension

// Show open file dialog box
Nullable<bool> result = dlg.ShowDialog();

// Process open file dialog box results
if (result == true)
{
    // Open document
    string filename = dlg.FileName;
}

*)