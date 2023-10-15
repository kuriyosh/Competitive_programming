use proconio::input;
use proconio::marker::Chars;

fn argsort<T: Ord>(v: &[T], asc: bool) -> Vec<usize> {
    let mut idx = (0..v.len()).collect::<Vec<_>>();
    idx.sort_unstable_by(|&i, &j| {
        if asc {
            v[j].cmp(&v[i])
        } else {
            v[i].cmp(&v[j])
        }
    });
    idx
}

fn main() {
    input! {
        n: usize,
        s: [Chars; n],
    }

    let mut result = vec![0; n];

    for i in 0..n {
        for j in 0..n {
            if s[i][j] == 'o' {
                result[i] += 1;
            }
        }
    }

    let sorted = argsort(&result, true)
        .iter()
        .map(|&x| (x + 1).to_string())
        .collect::<Vec<String>>()
        .join(" ");

    println!("{}", sorted);
}
