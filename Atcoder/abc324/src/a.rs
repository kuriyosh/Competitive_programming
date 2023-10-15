use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [u64; n],
    }

    let anc = a[0];

    if a.iter().all(|&x| x == anc) {
        println!("Yes");
    } else {
        println!("No");
    }
}
