use proconio::input;

fn main() {
    input! {
        (n, m): (usize, usize),
        c: [String; n],
        d: [String; m],
        p: [usize; m+1],
    }

    let get_price = |search: String| {
        let i = d.iter().position(|x| x == &search);
        match i {
            Some(i) => p[i + 1],
            None => p[0],
        }
    };

    println!("{}", c.iter().map(|c| get_price(c.clone())).sum::<usize>());
}
