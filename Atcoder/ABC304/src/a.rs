use proconio::input;

fn main() {
    input! {
        n: usize,
    }

    let mut v = Vec::<String>::new();
    let mut min = std::usize::MAX;
    let mut start = 0;
    for i in 0..n {
        input! {
            s: String,
            a: usize,
        }
        v.push(s);
        if a < min {
            min = a;
            start = i
        }
    }

    for i in start..n {
        println!("{}", v[i])
    }

    for i in 0..start {
        println!("{}", v[i])
    }
}
