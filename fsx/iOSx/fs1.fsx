open System

//printfn "Hello World!"
//printfn "%{0}" DateTime.Now.ToString

open Xamarin.Forms

let stack = StackLayout(VerticalOptions = LayoutOptions.Center) 
let label x = Label(XAlign = TextAlignment.Center, Text = x)
let res=label("*")

let cal() = DatePicker(
    MinimumDate = DateTime(1800, 1,1),
    MaximumDate = DateTime(2200, 1,1),
    Date = DateTime.Now)
   
let cal1=cal()
let cal2=cal()

//let dy (a)= let n=Math.Abs((cal1.Date-cal2.Date).TotalDays)/365.2425
    //do res.Text <-n.ToString()
cal1.DateSelected.AddHandler(fun s ea -> System.Console.Beep())

//cal1.DateSelected.Add dy 
//cal2.DateSelected.Add dy

stack.Children.Add(label "start date")
stack.Children.Add(cal1)
stack.Children.Add(label "End date")
stack.Children.Add(cal2)
stack.Children.Add(res)

let Main = ContentPage(
    Content = stack
)