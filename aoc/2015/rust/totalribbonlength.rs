// How many total feet of ribbon should they order?
// list of the dimensions (length l, width w, and height h) of each present
// The ribbon required to wrap a present is the shortest distance around 
// its sides, or the smallest perimeter of any one face. Each present also 
// requires a bow made out of ribbon as well; the feet of ribbon required 
// for the perfect bow is equal to the cubic feet of volume of the present.
//
// A present with dimensions 2x3x4 requires 2+2+3+3 = 10 feet of ribbon to wrap 
// the present plus 2*3*4 = 24 feet of ribbon for the bow, for a total of 34 feet.

use std::fs::File;
use std::io::{self, BufRead};
use std::cmp;

fn main() -> io::Result<()> {
    let path = "day2input.txt";
    let file = File::open(path)?;
    let reader = io::BufReader::new(file);
    let mut total_ribbon_length: u32 = 0;

    // Read line by line
    for line in reader.lines() {
        let line = line?;
        // Parse "1x2x3" format
        let dimensions: Vec<u32> = line
            .split('x')
            .map(|s| s.trim().parse::<u32>().expect("Failed to parse integer"))
            .collect();

        if dimensions.len() == 3 {
            let l = dimensions[0];
            let w = dimensions[1];
            let h = dimensions[2];

            let ribbon_length = cmp::min(l+w, cmp::min(w+h, l+h));
            let bow_length = l * w * h;

            total_ribbon_length += (2 * ribbon_length) + bow_length;
        }
    }
    println!("Total square feet of wrapping paper required {}", total_ribbon_length);

    Ok(())
}
