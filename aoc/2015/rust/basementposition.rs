// An opening parenthesis, (, means he should go up one floor, 
// and a closing parenthesis, ), means he should go down one floor.
// 
// The apartment building is very tall, and the basement is very deep;
//
// What is the position of the character that causes Santa to first enter the basement? (ie. floor -1)

use std::fs::File;
use std::io::{self, Read};

fn main() -> io::Result<()> {
    let mut file = File::open("../day1input.txt")?;

    // Initialize a string to store the file contents
    let mut line = String::new();
    
    // Read the file contents into the string
    file.read_to_string(&mut line)?;

    let mut floor = 0;
    let mut position = 0;

    for (index, ch) in line.char_indices() {
        if ch == '(' {
            floor = floor + 1; // increment the counter
        } else {
            floor = floor - 1; // decrement the counter
        }

        if floor == -1 {
            position = index+1;
            break;
        }
    }

    println!("Santa reaches the first basement floor at position {}", position);

    Ok(())
}
