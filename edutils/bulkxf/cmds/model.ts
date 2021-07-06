

export enum Cmd
{
  Void, 
  Copy, 
  Move,
}

// export interface ICommand
// {
//   depends: ICommand;
//   cmd: Cmd;
//   completed: boolean;
// }

export function command(cmd:Cmd,model:string[]):string{
  switch(cmd){
    case Cmd.Copy:
      let copy:string="copy"
      return supported(copy,model)
    case Cmd.Move:
      let move:string="move"
      return supported(move,model)
    default:
      throw new Error('Unsupported command encountered.  Does enum match template.json?');
  }
}
function supported(cmd:string,a:string[]):string{
  try{
    if (a.includes(cmd))
      return cmd
    else
      throw new Error('Unsupported command encountered.  Please add to template.json');
  }catch(e){
    console.log(e);
    Deno.exit(1);
  }
}