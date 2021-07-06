
#load "../.paket/load/netcoreapp3.1/FSharp.Data.fsx"

open System.IO // Name spaces can be opened just as modules
open System;
open FSharp.Data
open System.Text.Json

type Command(dependency: Command) =
  let depends = dependency
  let completed : bool = false

type JsonModel() = 
  member val source:string = "" with get,set
  member val rootDest:string = "" with get,set
  member val commands:Command array = [||] with get,set
  member val undo:Command array = [||] with get,set
  member val redo:Command array = [||] with get,set
  member val supportedCommands:string array = [||] with get, set

type Human ()= 
  member val FullName : string ="Alican Demirtas" with get, set
  member val Age : int = 22 with get, set

type Robot = Guid * string
type Race = Human | Robot

type JsonModel2 = JsonProvider<"../model.json", ResolutionFolder=__SOURCE_DIRECTORY__>
let sample = JsonModel2.GetSample() 
let model = JsonModel2.Parse(sample.ToString()) 
let model2= JsonSerializer.Deserialize<JsonModel> (sample.ToString())
// let human = new Human()
// let robot = Guid.NewGuid(), "RZ-210"
// let race = Human

model2.source <- "hello"
// let humanJson = JsonSerializer.Serialize human
// let robotJson = JsonSerializer.Serialize robot
// let raceJson = JsonSerializer.Serialize race

// let humanDeserialized = JsonSerializer.Deserialize<Human> humanJson
// let robotDeserialized = JsonSerializer.Deserialize<Robot> robotJson
// let raceDeserialized = JsonSerializer.Deserialize<Race> raceJson
printfn "%A" model2.source
// File.WriteAllText("model.json", simple.ToString())
// let msg = File.ReadAllText("test.txt")
//let msg = simple.ToString()
//printfn "%s" msg