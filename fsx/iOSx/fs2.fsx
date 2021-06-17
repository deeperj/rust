open System
open Xamarin.Forms
let v=Label(Text="hi")
let dy = ((DateTime.Now-DateTime.Now.AddDays(400.)).TotalDays)/365.2425

let dx ()= 
    do 
        let n= ((DateTime.Now-DateTime.Now.AddDays(400.)).TotalDays)/365.2425
        v.Text<-n.ToString()


printfn "Hello World! %A" v

printfn "Hello World! %A" dx()