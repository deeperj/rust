open System
open System.Windows
open System.Windows.Controls

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

b.Click.AddHandler(fun s ea -> System.Console.Beep())
sp.Children.Add b |> ignore

sp.Children.Add dp1 |> ignore
w.Content <- sp

[<STAThread>]
do a.Run(w) |> ignore

(*
open System.IO // Name spaces can be opened just as modules
File.WriteAllText("test.txt", "Hello There\n Welcome to:\n Tutorials Point")
let msg = File.ReadAllText("test.txt")
printfn "%s" msg
*)
