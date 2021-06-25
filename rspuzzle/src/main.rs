
// Import data types for testing
use std::{i8, i16, i32, i64, u8, u16, u32, u64, isize, usize, f32, f64};
 
use std::io::stdin;

fn main() {

    //let rand_string = "012345678";

    // String length
    //println!("Length : {}\n {}", rand_string.len(),rand_string.chars().nth(0).unwrap());
/*
    // Split a string in half at index
    let (first, second) = rand_string.split_at(6);
    println!("First : {} Second : {}", first, second);

    // Return an iterator for the string
    let count = rand_string.chars().count();
    let mut chars = rand_string.chars();

    let mut indiv_char = chars.next();

    loop {
        // Pattern match like switch
        match indiv_char {

            // If show print
            Some(x) => println!("{}", x),

            // If None break
            None => break,
        }
        indiv_char = chars.next();
    }

    // Split on whitespace
    let mut iter = rand_string.split_whitespace();

    let mut indiv_word = iter.next();

    loop {
        match indiv_word {
            Some(x) => println!("{}", x),
            None => break,
        }
        indiv_word = iter.next();
    }

    // Iterate over lines of string
    let rand_string2 = "I am a random string\nThere are other strings like it\nThis string is the best";

    let mut lines = rand_string2.lines();

    let mut indiv_line = lines.next();

    loop {
        match indiv_line {
            Some(x) => println!("{}", x),
            None => break,
        }
        indiv_line = lines.next();
    }

    // Find string in string
    println!("Find Best : {}", rand_string2.contains("best"));
    */
}
