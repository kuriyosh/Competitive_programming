use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i32; n * 7],
    }

    let mut ans: Vec<i32> = Vec::new();
    for sub in a.chunks(7) {
        ans.push(sub.iter().sum());
    }

    println!(
        "{}",
        ans.iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(" ")
    );
}
