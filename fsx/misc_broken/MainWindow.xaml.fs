namespace FirstDemo
type MainWindowXaml = FsXaml.XAML<"MainWindow.xaml">
type MainWindow() as this =
  inherit MainWindowXaml()

  let whenLoaded _ =
    ()
  let whenClosing _ =
    ()
  let whenClosed _ =
    ()
  let btnTestClick _ =
    this.Title <- "Yup, it works!"
  do
    this.Loaded.Add whenLoaded
    this.Closing.Add whenClosing
    this.Closed.Add whenClosed
    this.btnTest.Click.Add btnTestClick
