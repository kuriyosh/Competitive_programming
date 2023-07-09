use proconio::input;

fn main() {
    input! {
        s: [i32; 8]
    }

    let is_increasing = s.windows(2).all(|w| w[0] <= w[1]);
    let is_in_range = s.iter().all(|&x| x % 25 == 0 && x >= 100 && x <= 675);

    if is_increasing && is_in_range {
        println!("Yes");
    } else {
        println!("No");
    }
}
