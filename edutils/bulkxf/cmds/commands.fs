module commands
  #if !COMPILED
  // #I "../../bin/Binaries/WebJobs.Script.Host"
  #r "refs/FSharp.Data.dll"
  #endif
  open System.IO
  open FSharp.Data
  open System.Text.Json
  open ui2


  // type Command(dependency: Command option) =
  //   let depends = dependency
  //   let completed : bool = false

  type Command(dependency: Command option) =
    member val depends:Command option = dependency with get,set
    member val completed : bool = false with get,set
    new() = Command(None)

  type ModelJson = JsonProvider<"../template.json", ResolutionFolder=__SOURCE_DIRECTORY__>
  type JsonModel() = 
    member val source:string = "" with get,set
    member val rootDest:string = "" with get,set
    member val commands:Command array = [||] with get,set
    member val undo:Command array = [||] with get,set
    member val redo:Command array = [||] with get,set
    member val supportedCommands:string array = [||] with get, set

  type CopyCommand(dependency: Command option) =
    inherit Command(dependency)
    new() = CopyCommand(None)

  type MoveCommand(dependency: Command option) =
    inherit Command(dependency)

  type RenameCommand(dependency: Command option) =
    inherit Command(dependency)

  type DeleteCommand(dependency: Command option) =
    inherit Command(dependency)

  let runCommands() :string = 
    let sample = ModelJson.GetSample() 
    let model = ModelJson.Parse(sample.ToString()) 
    let model2= JsonSerializer.Deserialize<JsonModel> (sample.ToString())
    let st=openFD()
    model2.source <- st
    model2.rootDest <- Path.GetDirectoryName(st)
    let cmd = new CopyCommand()
    model2.commands <- ( model2.commands |> Array.append [|cmd|])
    let new_model = JsonSerializer.Serialize (new CopyCommand())
    File.WriteAllText("../model.json", new_model)
    new_model
