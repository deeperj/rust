open System.IO // Name spaces can be opened just as modules
File.WriteAllText("test.txt", "Hello There\n Welcome to:\n Tutorials Point")
let msg = File.ReadAllText("test.txt")
printfn "%s" msg