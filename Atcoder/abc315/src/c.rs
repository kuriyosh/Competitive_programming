use proconio::input;

fn main() {
    input! {
        n: usize,
    }

    let mut arr = Vec::<(usize, usize)>::new();
    let mut max_index = 0;

    for i in 0..n {
        input! {
            a: usize,
            b: usize,
        }
        arr.push((a, b));
        if arr[max_index].1 < b {
            max_index = i;
        }
    }

    let mut cand = 0;
    for i in 0..n {
        if i != max_index {
            cand = std::cmp::max(cand, get_pair_sum(arr[max_index], arr[i]));
        }
    }

    println!("{}", cand);
}

fn get_pair_sum(a: (usize, usize), b: (usize, usize)) -> usize {
    if a.0 == b.0 {
        a.1 + b.1 / 2
    } else {
        a.1 + b.1
    }
}
