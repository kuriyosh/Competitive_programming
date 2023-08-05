use proconio::input;

fn main() {
    input! {
        n: usize,
        d: usize,
    }

    let mut sum = vec![true; d];
    for _ in 0..n {
        input! {
            s: String,
        }
        let chars = s.chars().collect::<Vec<char>>();
        for j in 0..d {
            if chars[j] == 'x' {
                sum[j] = false;
            }
        }
    }

    let mut ans = 0;
    let mut tmp = 0;
    for s in sum {
        if s {
            tmp += 1;
            ans = std::cmp::max(ans, tmp);
        } else {
            tmp = 0;
        }
    }

    println!("{}", ans);
}
