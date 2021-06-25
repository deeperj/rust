
#load ".paket/load/netcoreapp3.1/FSharp.Data.fsx"

open System.IO // Name spaces can be opened just as modules
open System;
open FSharp.Data

//type Simple = CsvProvider<""" "name","age"\n"John",94 """>
type Simple = JsonProvider<"model.json", ResolutionFolder=__SOURCE_DIRECTORY__>
let simple = Simple.GetSample() 
simple.Age
simple.Name
printfn "%A" simple
// File.WriteAllText("model.json", simple.ToString())
// let msg = File.ReadAllText("test.txt")
//let msg = simple.ToString()
//printfn "%s" msg