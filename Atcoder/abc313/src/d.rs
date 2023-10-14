use proconio::input;
use std::io::{stdout, Write};

fn main() {
    input! {
        n: usize,
        k: usize,
    }

    let mut ans = vec![false; n];

    let mut before = 0;
    for i in 0..(n - k + 1) {
        let mut tmp = vec![];
        for j in i..i + k {
            tmp.push(j)
        }
        println!(
            "? {}",
            tmp.iter()
                .map(|x| x.to_string())
                .collect::<Vec<String>>()
                .join(" ")
        );

        input! {
            sum: usize
        }

        if i == 0 {
            before = sum;
            continue;
        }

        if sum > before {
            ans[i] = false;
        } else {
            ans[i] = true;
        }

        before = sum;
        stdout().flush().unwrap();
    }

    for _ in 0..k {
        if before > 0 {
            ans.push(true);
            before -= 1;
        }
    }

    let ans_str = ans
        .iter()
        .map(|x| if *x { "1" } else { "0" })
        .collect::<Vec<&str>>()
        .join(" ");
    println!("! {}", ans_str);
}
