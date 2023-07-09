use proconio::input;

fn main() {
    input! {
        a: i32,
        b: i32
    }

    if a % 3 == 1 && ((b - a) == 1) {
        println!("Yes");
        return;
    }
    if a % 3 == 2 && ((b - a) == 1) {
        println!("Yes");
        return;
    }

    println!("No");
}
