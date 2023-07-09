use proconio::input;

fn main() {
    input! {
        n: usize,
        k: usize,
        mut ab: [(usize, usize); n],
    }

    ab.sort_by(|a, b| a.0.cmp(&b.0));
    let mut sum = ab.iter().map(|a| a.1).sum::<usize>();

    if sum <= k {
        println!("1");
        return;
    }

    for i in 0..n {
        sum = sum - ab[i].1;
        if sum <= k {
            println!("{}", ab[i].0 + 1);
            return;
        }
    }
}
