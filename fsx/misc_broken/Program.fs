// Learn more about F# at http://fsharp.org
namespace foreign
open System

let square x = x * x

let sumOfSquares n =
    [1..n] // create a new list with values 1 to n
    |> List.map square //square each
    |> List.sum // reduce

let other argv =
    printfn "sum of first 5 squares is %d" (sumOfSquares 5)
    0 // return an integer exit code

