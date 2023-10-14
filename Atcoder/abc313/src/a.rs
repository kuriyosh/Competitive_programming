use proconio::input;

fn main() {
    input! {
        n: usize,
    }

    let mut max_n: i32 = -1;
    let mut max_num = 0;
    let mut start = 0;

    for i in 0..n {
        input! {
            a: usize,
        }
        if i == 0 {
            start = a;
            max_n = a as i32;
        };

        if a == max_n as usize {
            max_num += 1;
        }

        if a > max_n as usize {
            max_n = a as i32;
            max_num = 1;
        }
    }

    if max_n == start as i32 && max_num == 1 {
        println!("0");
    } else {
        println!("{}", max_n + 1 - start as i32);
    }
}
