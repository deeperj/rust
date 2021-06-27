module ui
  open System
  open System.Windows
  open System.Windows.Controls
  open commands

  [<Class>]
  type Store () =
    let mutable undo:bool = false;
    member this.Undo
        with get () = undo
        and set (value) = undo <- value

  let state = Store()

  let RunApp()  =
    let a = Application()
    let w = Window()
    w.SizeToContent <- SizeToContent.WidthAndHeight
    printf "setting up..\n" 

    let sp = StackPanel()

    let t = TextBlock()
    t.Text <- "hello\n world"

    sp.Children.Add t |> ignore

    let b = Button()
    b.Content <- "Select"

    b.Click.AddHandler(fun s ea -> 
      if not state.Undo then
        t.Text <- runCommands()
        b.Content <- "Undo"
      else
        b.Content <- "Select"
      state.Undo <- not state.Undo
    )
    sp.Children.Add b |> ignore

    w.Content <- sp

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