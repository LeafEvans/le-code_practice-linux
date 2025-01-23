use std::io::{self, Write};

fn main() {
    let num1 = get_number("Enter the first number: ");

    let num2 = get_number("Enter the second number: ");

    let operation = get_operation();

    match operation {
        Operation::Add => println!("Result: {}", num1 + num2),
        Operation::Subtract => println!("Result: {}", num1 - num2),
        Operation::Multiply => println!("Result: {}", num1 * num2),
        Operation::Divide => {
            if num2 == 0.0 {
                println!("Error: Division by zero is not allowed.");
            } else {
                println!("Result: {}", num1 / num2);
            }
        }
    }
}

fn get_number(prompt: &str) -> f64 {
    loop {
        print!("{}", prompt);
        io::stdout().flush().unwrap();

        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        match input.trim().parse::<f64>() {
            Ok(num) => return num,
            Err(_) => println!("Please enter a valid number."),
        }
    }
}

fn get_operation() -> Operation {
    loop {
        println!("Choose an operation:");
        println!("1. Add");
        println!("2. Subtract");
        println!("3. Multiply");
        println!("4. Divide");

        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        match input.trim() {
            "1" => return Operation::Add,
            "2" => return Operation::Subtract,
            "3" => return Operation::Multiply,
            "4" => return Operation::Divide,
            _ => println!("Invalid choice. Please select 1, 2, 3, or 4."),
        }
    }
}

enum Operation {
    Add,
    Subtract,
    Multiply,
    Divide,
}
