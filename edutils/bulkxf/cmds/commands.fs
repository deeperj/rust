module commands
  #if !COMPILED
  // #I "../../bin/Binaries/WebJobs.Script.Host"
  #r "refs/FSharp.Data.dll"
  #endif
  open System.IO
  open FSharp.Data
  open System.Text
  open System.Diagnostics
  open System.Text.Json
  open ui2

  type System.String with
    member s1.icompare(s2: string) =
    System.String.Equals(s1, s2, System.StringComparison.CurrentCultureIgnoreCase);;

  // type Command(dependency: Command option) =
  //   let depends = dependency
  //   let completed : bool = false

  type Command =
    | Void
    | Copy

  // let GetCommandStr cmd:Command  arr:string[] =
  //   let res = cmd.ToString().ToLower()
  //   match arr |> Array.contains res with
  //     | true -> res
  //     | _ -> failwith "Command Not Supported. Edit template.json to add more commands."

  // type ICommand(cmd: Command, ?dependency: ICommand option) =
  //   member val cmd : Command = cmd with get,set
  //   member val depends:ICommand option = defaultArg dependency None with get,set
  //   member val completed : bool = false with get,set
  //   new() = ICommand(Command.Void)

  type ModelJson = JsonProvider<"../template.json", ResolutionFolder=__SOURCE_DIRECTORY__>
  type JsonModel() = 
    member val source:string = "" with get,set
    member val rootDest:string = "" with get,set
    member val commands:string array = [||] with get,set
    member val undo:string array = [||] with get,set
    member val redo:string array = [||] with get,set
    member val supportedCommands:string array = [||] with get, set

  // type CopyCommand(dependency: Command option) =
  //   inherit Command(dependency)
  //   new() = CopyCommand(None)

  // type MoveCommand(dependency: Command option) =
  //   inherit Command(dependency)

  // type RenameCommand(dependency: Command option) =
  //   inherit Command(dependency)

  // type DeleteCommand(dependency: Command option) =
  //   inherit Command(dependency)

  let RunDeno() :string = 
    let proc = new Process() 
    proc.StartInfo <- new ProcessStartInfo()
    proc.StartInfo.FileName <- "ls"
    // proc.StartInfo.Arguments  "command line arguments to your executable",
    proc.StartInfo.UseShellExecute <- false
    proc.StartInfo.RedirectStandardOutput <- true
    proc.StartInfo.CreateNoWindow <- true
    proc.Start();
    let sb = StringBuilder()
    while not proc.StandardOutput.EndOfStream do
      sb.AppendLine( proc.StandardOutput.ReadLine());
    sb.ToString()

  let runCommands() :string = 
    let sample = ModelJson.GetSample() 
    let model = ModelJson.Parse(sample.ToString()) 
    let model2= JsonSerializer.Deserialize<JsonModel> (sample.ToString())
    let st=openFD()
    model2.source <- st
    model2.rootDest <- Path.GetDirectoryName(st)
    let cmdStr = Command.Copy.ToString().ToLower()
    // let cmd = match model2.supportedCommands |> Array.contains cmdStr with
    //   | true -> cmdStr
    //   | _ -> failwith "Command Not Supported. Edit template.json to add more commands."
    model2.commands <- ( model2.commands |> Array.append [|"copy"|])
    let new_model = JsonSerializer.Serialize model2
    File.WriteAllText("../model.json", new_model)
    // let msg = File.ReadAllText("../model.json")
    printfn "%s" new_model
    new_model; //RunDeno()
