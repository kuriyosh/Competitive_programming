use proconio::input;
use proconio::marker::Chars;

fn main() {
    input! {
        n: usize,
        a: [Chars; n],
    }

    for i in 0..n {
        let mut row = Vec::<char>::new();
        if i == 0 {
            row.push(a[1][0]);
            row.extend(&a[0][0..n - 1]);
        }
        if i > 0 && i < n - 1 {
            row.push(a[i + 1][0]);
            row.extend(&a[i][1..n - 1]);
            row.push(a[i - 1][n - 1])
        }
        if i == n - 1 {
            row.extend(&a[i][1..n]);
            row.push(a[n - 2][n - 1])
        }
        println!("{}", row.iter().collect::<String>());
    }
}
