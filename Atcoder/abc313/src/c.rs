use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [usize; n]
    }

    let down = (a.iter().sum::<usize>() as f64 / n as f64).floor() as usize;
    let up = (a.iter().sum::<usize>() as f64 / n as f64).ceil() as usize;

    let mut add = 0;
    let mut minus = 0;
    for i in 0..n {
        if a[i] < down {
            add += down - a[i];
        }
        if a[i] > up {
            minus += a[i] - up;
        }
    }

    println!("{}", std::cmp::max(add, minus));
}
