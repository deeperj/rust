
// Import data types for testing
use std::{i8, i16, i32, i64, u8, u16, u32, u64, isize, usize, f32, f64};
 
use std::io::stdin;
 
// The main function executes when you run the program
pub fn run() {
    let mut x = 1;

    loop {
        // If even print number
        if((x % 2) == 0) {
            println!("{}", x);
            x += 1;

            // Jump back to the beginning of the loop
            continue;
        }
        if(x > 10){

            // Jump out of the loop
            break;
        }
        x += 1;
        continue;

    }

    let mut y = 1;

    while y <= 10 {
        println!("WHILE : {}", y);
        y += 1;
    }

    for z in 1..10 {
        println!("FOR : {}", z);
    }
}

