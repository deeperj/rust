type Greetings(name) as gr =
   let data = name
   do
      gr.PrintMessage()
   member this.PrintMessage() =
      printf "Hello %s\n" data
let gtr = new Greetings("Zara")