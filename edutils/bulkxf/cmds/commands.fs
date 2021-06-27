module commands
  #if !COMPILED
  // #I "../../bin/Binaries/WebJobs.Script.Host"
  #r "refs/FSharp.Data.dll"
  #endif
  open System.IO
  open FSharp.Data
  open System.Text.Json
  open ui2


  type Command(dependency: Command) =
    let depends = dependency
    let completed : bool = false

  type ModelJson = JsonProvider<"../model.json", ResolutionFolder=__SOURCE_DIRECTORY__>
  type JsonModel() = 
    member val source:string = "" with get,set
    member val rootDest:string = "" with get,set
    member val commands:Command array = [||] with get,set
    member val undo:Command array = [||] with get,set
    member val redo:Command array = [||] with get,set
    member val supportedCommands:string array = [||] with get, set

  type CopyCommand(dependency: Command) =
    inherit Command(dependency)

  type MoveCommand(dependency: Command) =
    inherit Command(dependency)

  type RenameCommand(dependency: Command) =
    inherit Command(dependency)

  type DeleteCommand(dependency: Command) =
    inherit Command(dependency)

  let runCommands() :string = 
    let sample = ModelJson.GetSample() 
    let model = ModelJson.Parse(sample.ToString()) 
    let model2= JsonSerializer.Deserialize<JsonModel> (sample.ToString())
    let st=openFD()
    model2.source <- st
    
    JsonSerializer.Serialize model2
