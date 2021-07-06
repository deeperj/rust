namespace mgtest


module Program =

    open System
    // open System.Windows.Forms
    // open System.Drawing
    open Microsoft.Xna.Framework


    [<EntryPoint>]
    let main argv =
        use game = new Game1()
        game.Run()
        0 // return an integer exit code

// let form = new Form(Text="F# Windows Form",
//                     Visible = true,
//                     TopMost = true)

// form.Click.Add(fun evArgs -> System.Console.Beep())

// [<STAThread>]
// do Application.Run(form)


