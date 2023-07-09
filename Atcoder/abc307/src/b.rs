use proconio::input;

fn main() {
    input! {
        n: usize,
        s: [String; n],
    }

    for i in 0..n {
        for j in i + 1..n {
            if is_batch(&s[i], &s[j]) {
                println!("Yes");
                return;
            }
        }
    }
    println!("No");
}

fn is_batch(a: &str, b: &str) -> bool {
    let compare = |s1: &str, s2: &str| {
        let concat = String::from(s1) + s2;
        concat == concat.chars().rev().collect::<String>()
    };

    compare(a, b) || compare(b, a)
}
