use proconio::input;
use std::collections::VecDeque;

fn main() {
    input! {
        _n: usize,
        a: String,
    }

    let mut ans: Vec<char> = vec![];
    let mut queue = VecDeque::<char>::new();

    for c in a.chars() {
        match c {
            '(' => queue.push_back(c),
            ')' => {
                if queue.is_empty() {
                    ans.push(c);
                } else {
                    while Some('(') != queue.pop_back() {}
                }
            }
            _ => {
                if queue.is_empty() {
                    ans.push(c);
                } else {
                    queue.push_back(c);
                }
            }
        }
    }

    println!(
        "{}{}",
        ans.iter().collect::<String>(),
        queue.iter().collect::<String>()
    );
}
