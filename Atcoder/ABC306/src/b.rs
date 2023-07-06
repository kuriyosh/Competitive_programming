use proconio::input;

fn main() {
    input! {
        mut a: [i32; 64]
    }
    let b = a
        .iter()
        .rev()
        .map(|x| x.to_string())
        .collect::<Vec<String>>()
        .join("");

    let ans = u64::from_str_radix(&b, 2).unwrap();
    println!("{}", ans);
}
