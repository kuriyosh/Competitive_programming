use proconio::{input, marker::Chars};
use std::cmp::min;

fn main() {
    input! {
        h: usize,
        w: usize,
        s: [Chars; h],
    }

    // h,w でクッキーが置かれてる最大の辺を求める
    let (start_h, start_w, longest) = get_range(&s, h, w);
    println!("{} {} {}", start_h, start_w, longest);

    let mut ans: (usize, usize) = (0, 0);
    'solver: for i in 0..h {
        for j in 0..w {
            if s[i][j] == '.'
                && i >= start_h
                && i < (start_h + longest)
                && j >= start_w
                && j < (start_w + longest)
            {
                ans = (i, j);
                break 'solver;
            }
        }
    }
    println!("{} {}", ans.0 + 1, ans.1 + 1);
}

fn get_range(s: &Vec<Vec<char>>, h: usize, w: usize) -> (usize, usize, usize) {
    let mut max = 0;
    let mut start_h = 501;
    let mut start_w = 501;
    for i in 0..h {
        let mut count = 0;
        for j in 0..w {
            if s[i][j] == '#' {
                start_h = min(start_h, i);
                start_w = min(start_w, j);
                count += 1;
            }
        }
        if count > max {
            max = count;
        }
    }
    (start_h, start_w, max)
}
