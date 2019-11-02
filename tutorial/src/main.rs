use std::env;
mod datatypes;
mod output;

fn main() {
  let args: Vec<String> = env::args().collect();
  let command = args[1].clone();

  // println!("Command: {}", command);

  if command == "datatypes" {
    datatypes::run();
  } else if command == "status" {
    output::run();
  } else {
    println!("That is not a valid command");
  }
}
