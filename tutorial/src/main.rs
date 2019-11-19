use std::env;
mod datatypes;
mod output;
mod math;
mod conditional;
mod loops;
mod strings;

fn main() {
  let args: Vec<String> = env::args().collect();
  let command = args[1].clone();

  // println!("Command: {}", command);

  if command == "datatypes" {
    datatypes::run();
  } else if command == "output" {
    output::run();
  } else if command == "math" {
    math::run();
  } else if command == "conditional" {
    conditional::run();
  } else if command == "loops" {
    loops::run();
  } else if command == "strings" {
    strings::run();
  } else {
    println!("That is not a valid command");
  }
}
