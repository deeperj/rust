
open Xamarin.Forms 

let stack = StackLayout(VerticalOptions = LayoutOptions.Center) 
let label = Label(XAlign = TextAlignment.Center, Text = "Welcome to F# Xamarin.Forms!")

stack.Children.Add(label)
let Main = ContentPage(
    Content = stack
)