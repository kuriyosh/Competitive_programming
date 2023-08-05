use std::collections::HashSet;

use proconio::input;

fn main() {
    input! {
        n: usize,
        s: String,
    }

    let mut set = HashSet::<char>::new();
    let chars = s.chars().collect::<Vec<char>>();
    for i in 0..n {
        set.insert(chars[i]);
        if set.len() == 3 {
            println!("{}", i + 1);
            return;
        }
    }
}
