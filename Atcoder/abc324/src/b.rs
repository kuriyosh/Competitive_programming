use proconio::input;

fn main() {
    input! {
        n: usize
    }

    let mut cur = n;
    while cur % 2 == 0 {
        cur /= 2;
    }

    while cur % 3 == 0 {
        cur /= 3;
    }

    if cur == 1 {
        println!("Yes");
    } else {
        println!("No");
    }
}
