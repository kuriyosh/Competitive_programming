use proconio::input;

fn main() {
    input! {
        p: char,
        q: char,
    }
    let range = [0, 3, 4, 8, 9, 14, 23];

    let p = range[p as usize - 'A' as usize];
    let q = range[q as usize - 'A' as usize];
    let t: i32 = p - q;

    println!("{}", t.abs());
}
