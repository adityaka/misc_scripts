

fn printTuple () {
    let tup:(i64, f32, char) = (102132123, 2.132, ':');
    println!("Values in tupple {} , {}, {}", tup.0, tup.1, tup.2);
    let (x,y,z) = tup;
    println!("Expaded values x={},y={},z={}", x, y, z);

}

fn printArray() {
    let array = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"];
    // bounds checking demo rust kills you on compile time 
    // println!("{}", array[8]);

    println!("days of week\n {},{},{},{},{},{},{},{}", array[0], array[1],array[2],array[3],array[4],array[5],array[6],array[7]);

}


fn main() {
    let mut x = 13;
    x = 31;
    let mut y:i32 = 2147483638;
    y+=1;
    let z:f32 = 1.232;
    let b:bool = false;
    if b {
        println!("b is true");
    }else{
        println!("b is false");
    }
    println!("var y = {} " , y);
    println!("var x = {}", x);
    println!("var z = {}", z);

    // Arrays and Tuples 
    printTuple();
    
    // Arrays are fixed size and cannot grow or shrink tupples can probably 
    printArray();
    
}
