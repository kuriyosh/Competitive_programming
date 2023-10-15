use proconio::{input, marker::Chars};

fn condition(s1: &Vec<char>, s2: &Vec<char>) -> bool {
    let mut s1 = s1.clone();
    let mut padding_s2 = s2.clone();

    let diff = (s1.len() as isize) - (s2.len() as isize);
    if diff < 0 {
        return false;
    }

    if diff > 0 {
        for _ in 0..s1.len() - s2.len() {
            padding_s2.push('0');
        }
    }

    s1.sort();
    padding_s2.sort();

    return s1 == padding_s2;
}

fn to_chars(n: usize) -> Vec<char> {
    return n.to_string().chars().collect::<Vec<char>>();
}

fn main() {
    input! {
        n: usize,
        s: Chars
    }

    let mut ans = 0;
    let mut current: usize = 1;
    while current.pow(2) < (10 as usize).pow((n + 1) as u32) {
        if condition(&s, &to_chars(current.pow(2))) {
            ans += 1;
        }
        current += 1;
    }

    println!("{}", ans);
}
