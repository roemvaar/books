fn main() {
    println!("Hello, world!");

    another_function(5);
    print_labeled_measurement(5, 'h');
    print_string(10, "❤️");

    let x = five();
    println!("The value of x is {x}");

    let a = 10;
    let b = 5;
    let result = add(a, b);
    println!("{a} + {b} = {result}");
}

fn another_function(x: i32) {
    println!("Another function.");
    println!("The value of x is: {x}");
}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The measurement is: {value}{unit_label}");
}

fn print_string(count: i32, emoji: &str) {
    for i in 0..count {
        println!("Loop[{i}]: {emoji}");
    }
}

fn five() -> i32 {
    return 5
}

fn add(a: i32, b: i32) -> i32 {
    return a + b
}
