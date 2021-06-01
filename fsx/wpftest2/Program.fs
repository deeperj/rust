open System
open System.Windows
open System.Windows.Controls

let a = Application()

let w = Window()
w.SizeToContent <- SizeToContent.WidthAndHeight

let sp = StackPanel()

let t = TextBlock()
t.Text <- "hello world"

sp.Children.Add t |> ignore

let b = Button()
b.Content <- "Click Me"

b.Click.AddHandler(fun s ea -> System.Console.Beep())
sp.Children.Add b |> ignore

w.Content <- sp

[<STAThread>]
do a.Run(w) |> ignore
