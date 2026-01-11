// Program to reverse a string

fn main() {
    let givenString: String = String::from("sample string");
    // Reversing using the iterators chars and rev
    // chars function returns an iterator of the chars in the string
    // rev function takes the iterator returned by the chars and 
    // creates an iterator that is the reverse of the chars
    // collect converts the iterator into collection. char iterator into string
    let reversed: String = givenString.chars().rev().collect();
    println!("{} is reversed as {}", givenString, reversed);

    // loop method
    // uses the reversed string and reverses it to original state
    // Using vec<char>, which helps to access each char with usize

    let mut index = reversed.len() - 1;
    let revChars: Vec<char> = reversed.chars().collect();

    let mut originalStr: String = String::new();
    loop {
        originalStr.push(revChars[index]);
        if index == 0 {
            break;
        }
        index -= 1;
    }
    println!("Original string is {}", originalStr);
    println!("Convertion status {}", originalStr == givenString);

    // It is best to use unicode_segmentation::UnicodeSegmentation crate to 
    // iterate over graphemes instead of chars
    // This is more useful, when the string contains multi-character grapheme clusters
    // Add this dependency in Cargo.toml => unicode-segmentation = "1.10.1"
        // let s = "mañana"; // Contains a combining character
        // let reversed: String = s.graphemes(true).rev().collect();
        // println!("Reversed: {}", reversed); 
}
