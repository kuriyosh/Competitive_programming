use std::collections::HashSet;

use proconio::input;

fn main() {
    input! {
        n: usize,
        s: [String; n]
    }

    let mut res = 0;
    let mut kind = HashSet::<String>::new();
    for i in 0..n {
        if !kind.contains(&s[i]) {
            res += 1;
            kind.insert(s[i].clone());
            kind.insert(s[i].chars().rev().collect::<String>());
        }
    }
    println!("{}", res);
}
