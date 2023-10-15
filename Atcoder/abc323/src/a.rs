use proconio::input;

fn main() {
    input! {
        s: String,
    }

    let res = s.chars().enumerate().all(|(i, c)| {
        if i % 2 == 1 {
            return c == '0';
        }
        true
    });

    if res {
        println!("Yes");
    } else {
        println!("No");
    }
}
