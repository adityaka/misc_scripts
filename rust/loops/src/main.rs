
fn loop_statement_demo(stopAt:i64){
    println!("loop statemet demo");
    let mut i = stopAt;
    loop{

        println!("{}", i);
        i-=1;
        if i == 0 {
            break;
        }
    }
}

fn while_loop_demo(stopAt:i64){
    println!("While statement demo");
    let mut i = stopAt;

    while i > 0 { 
        println!("{}", i);
        i-=1;
    }
}

fn for_loop_demo(a:&[i64]){
    println!("for loop demo");
    for i in a.iter() {
        println!("{}", i);
    }
}
fn main() {
    let numbers:[i64;10] = [1,2,3,4,5,6,7,8,9,10];
    loop_statement_demo(10);
    while_loop_demo(10);
    for_loop_demo(&numbers);

}
