use proconio::input;
use std::cmp;

fn main() {
    input! {
        n: usize,
        p: usize,
        q: usize,
        d: [usize; n]
    }

    let min = d.iter().min().unwrap();

    println!("{}", cmp::min(p, min + q));
}
