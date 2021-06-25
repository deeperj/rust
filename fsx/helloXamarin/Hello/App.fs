namespace Hello

open Xamarin.Forms

type App() = 
    inherit Application()

    let stack = StackLayout(VerticalOptions = LayoutOptions.Center)
    let label = Label(HorizontalTextAlignment = TextAlignment.Center,
                      Text = "Welcome to F# Xamarin.Forms!")

// divideButton.Clicked.Add(fun _ -> number <- number / 2.0
                                        //  do label.Text <- number.ToString())
    do stack.Children.Add(label)
    do base.MainPage <- ContentPage(Content = stack)
    
