// An opening parenthesis, (, means he should go up one floor, 
// and a closing parenthesis, ), means he should go down one floor.
// 
// The apartment building is very tall, and the basement is very deep;
//
// To what floor do the instructions take Santa?

use std::fs::File;
use std::io::{self, Read};

fn main() -> io::Result<()> {
    let mut file = File::open("../day1input.txt")?;

    // Initialize a string to store the file contents
    let mut line = String::new();
    
    // Read the file contents into the string
    file.read_to_string(&mut line)?;

    let mut floor = 0;

    for ch in line.chars() {
        if ch == '(' {
            floor = floor + 1; // increment the counter
        } else {
            floor = floor - 1; // decrement the counter
        }
    }

    println!("Santa reaches the floor {}", floor);

    Ok(())
}
