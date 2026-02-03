// How many total square feet of wrapping paper should Elves order?
// list of the dimensions (length l, width w, and height h) of each present
// every present is a box (a perfect right rectangular prism), which makes 
// calculating the required wrapping paper for each gift a little easier: 
// find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l. 
// The elves also need a little extra paper for each present: the area of the smallest side.
//
// A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet 
// of wrapping paper plus 6 square feet of slack, for a total of 58 square feet.

use std::fs::File;
use std::io::{self, BufRead};
use std::cmp;

fn main() -> io::Result<()> {
    let path = "day2input.txt";
    let file = File::open(path)?;
    let reader = io::BufReader::new(file);
    let mut total_wrapping_length: u32 = 0;

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

            let lw = l*w;
            let wh = w*h;
            let lh = l*h;

            let small_side_area = cmp::min(lw, cmp::min(wh, lh));
            let box_area = (2*lw) + (2*wh) + (2*lh);

            total_wrapping_length += small_side_area + box_area;
        }
    }
    println!("Total square feet of wrapping paper required {}", total_wrapping_length);

    Ok(())
}
