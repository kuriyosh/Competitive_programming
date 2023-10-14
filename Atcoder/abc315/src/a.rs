use proconio::input;

fn main() {
    input! {
        s: String,
    }

    let filter = vec!['a', 'e', 'i', 'o', 'u'];

    let ans = s
        .chars()
        .filter(|&c| filter.iter().all(|f| f != &c))
        .collect::<String>();

    println!("{}", ans);
}
