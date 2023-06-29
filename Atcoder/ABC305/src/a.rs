use proconio::input;

fn main() {
    input! {
        n: i32
    }

    let mod_n = n % 5;

    let v = if mod_n <= 2 { n - mod_n } else { n - mod_n + 5 };

    println!("{}", v);
}
