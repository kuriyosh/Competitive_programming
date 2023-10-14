use proconio::input;

fn main() {
    input! {
        m: usize,
        d: [usize; m],
    }

    let sum = d.iter().sum::<usize>();

    let mut half: i32 = if sum % 2 == 0 {
        (sum / 2) as i32
    } else {
        ((sum + 1) / 2) as i32
    };

    for i in 0..m {
        half -= d[i] as i32;
        if half <= 0 {
            println!("{} {}", i + 1, d[i] as i32 + half);
            return;
        }
    }
}
