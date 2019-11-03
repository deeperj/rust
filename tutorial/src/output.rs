// Import data types for testing
use std::{i8, i16, i32, i64, u8, u16, u32, u64, isize, usize, f32, f64};
 
use std::io::stdin;
 
// The main function executes when you run the program
pub fn run() {
     // There are booleans
    let is_it_true: bool = true;
    // Characters
    let let_x: char = 'x';
       // You can place data multiple times
    println!("It is {0} that {1} is {0}",
    is_it_true, let_x);

    // Format output
    println!("{:.2}", 1.234);
    println!("B: {:b} H: {:x} O: {:o}", 10, 10, 10);

    // Use named arguments
    // Define whitespace before data
    println!("{ten:>ws$}", ten=10, ws=5);

    // Pad output with zeros
    println!("{ten:>0ws$}", ten=10, ws=5);
}