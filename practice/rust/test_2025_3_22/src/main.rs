mod shapes {
    pub struct Rectangle {
        pub width: f64,
        pub height: f64,
    }

    pub fn calculate_area(rect: &Rectangle) -> f64 {
        rect.width * rect.height
    }

    pub mod utils {
        pub fn double_value(x: f64) -> f64 {
            x * 2.0
        }
    }
}

fn main() {
    let rect = shapes::Rectangle {
        width: 10.0,
        height: 5.0,
    };
    println!("面积: {}", shapes::calculate_area(&rect));

    println!("双倍宽度: {}", shapes::utils::double_value(rect.width));

    use shapes::utils::double_value;
    println!("双倍高度: {}", double_value(rect.height));
}
