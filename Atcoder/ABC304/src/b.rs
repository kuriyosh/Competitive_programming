use proconio::input;

fn main() {
    input! {
        n: usize
    }

    if n < 10_usize.pow(3) {
        println!("{}", n);
        return;
    }

    for i in 4..10 {
        if n < 10_usize.pow(i) {
            let sub = n % 10_usize.pow(i - 3);
            println!("{}", n - sub);
            return;
        }
    }
}
