

import { Cmd, command } from './model.ts'

export async function processCommands(){
  const model = JSON.parse(Deno.readTextFileSync('./model.json'));
  //console.log(model)
  try{
    for(const cmd of model.commands){
      switch(cmd){
        case command(Cmd.Copy, model.supportedCommands):
          const dest:string = model.rootDest + "/" + model.rootDestFileName
          await Deno.copyFile(model.source, dest);
          console.log("copied from ",model.source," to ",dest)
      }
    }
  }catch(e){
    console.log(e);
    Deno.exit(1);
  }
}
