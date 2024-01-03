fn main() {
    println!("Hello, world!");
    from_fahr_to_celsius(100.0);
    from_celsius_to_fahr(40.0);

    let num = fibonacci(15);
    println!("{}", num);

    sing_xmas_carol();
}

// Convert temperatures between Fahrenheit and Celsius
fn from_fahr_to_celsius(fahr: f64) {
    let celsius = (fahr - 32.0) * (5.0/9.0);

    println!("{}°F = {:.2}°C", fahr, celsius);
}

fn from_celsius_to_fahr(celsius: f64) {
    let fahr = (celsius * (9.0/5.0)) + 32.0;

    println!("{}°C = {:.2}°F", celsius, fahr);
}

// Generate the nth Fibonacci number
fn fibonacci(n: i32) -> i32 {
    if n == 0 {
        return 0;
    }
    if n == 1 {
        return 1;
    }

    fibonacci(n - 1) + fibonacci(n - 2)
}

// Print the lyrics to the carol "The Twelve Days of
// Christmas," taking advantage of the repetition in the song
fn sing_xmas_carol() {
    let days: [&str; 12] = [
        "a partridge in a pear tree",
        "two turtle doves",
        "three french hens",
        "four calling birds",
        "FIVE GOLD RINGS",
        "six geese a-laying",
        "seven swans a-swimming",
        "eight maids a-milking",
        "nine ladies dancing",
        "ten lords a-leaping",
        "eleven pipers piping",
        "twelve drummers drumming",
    ];

    for day in 0..12 {
        let suffix: &str = match day + 1 {
            1 => "st",
            2 => "nd",
            3 => "rd",
            _ => "th",
        };
        println!("\nOn the {}{} day of xmas my true love gave to me:", day + 1, suffix);
        for item in (0..day + 1).rev() {
            if day > 0 && item == 0 {
                print!("And ");
            }
            println!("{}", days[item]);
        }
    }
}
