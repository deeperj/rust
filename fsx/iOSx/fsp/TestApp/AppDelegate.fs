namespace TestApp

open System

open Foundation
open UIKit


[<Register ("AppDelegate")>]
type AppDelegate() =
    inherit UIApplicationDelegate()
    override val Window = null with get, set

    override this.FinishedLaunching (application, launchOptions) =
        this.Window <- new UIWindow (UIScreen.MainScreen.Bounds)
        this.Window.RootViewController <- new MyViewController ()
        this.Window.MakeKeyAndVisible ()
        true

