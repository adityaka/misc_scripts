fn main() {
    let mut message = String::from("Hello ");
    message.push_str("Aditya Kapur");
    //mutable references : there can only be one 
    let mut s1 = message; // this is a move operation for mutable references
    // this won't work
    // println!("{}", message );
    println!("string message = {}\nstring length {}", s1, s1.capacity());
    s1.push_str("\n This is a crappy string message");
    println!("string message = {}\nstring length {}", s1, s1.len());
}
