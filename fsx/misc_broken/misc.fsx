
#r "pkg/FSharp.Data.dll"
open System;
open FSharp.Data
//type Simple = CsvProvider<""" "name","age"\n"John",94 """>
type Simple = JsonProvider<""" { "name":"John", "age":94 } """>
let simple = Simple.Parse(""" { "name":"Tomas", "age":4 } """)
simple.Age
simple.Name
printfn "%A" simple