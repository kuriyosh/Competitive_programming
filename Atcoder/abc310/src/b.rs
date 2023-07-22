use proconio::input;
use std::collections::HashSet;

fn main() {
    input! {
        n: usize,
        m: usize,
    }

    let mut prices = vec![0; n];
    let mut functions = vec![HashSet::<usize>::new(); n];
    for i in 0..n {
        input! {
            p: usize,
            c: usize,
            f: [usize; c]
        }
        prices[i] = p;
        functions[i] = f.into_iter().collect();

        for j in 0..i {
            if comp(
                (prices[i], functions[i].clone()),
                (prices[j], functions[j].clone()),
            ) || comp(
                (prices[j], functions[j].clone()),
                (prices[i], functions[i].clone()),
            ) {
                println!("Yes");
                return;
            }
        }
    }

    println!("No");
}

fn comp((p1, fs1): (usize, HashSet<usize>), (p2, fs2): (usize, HashSet<usize>)) -> bool {
    let is_contained = fs2.iter().all(|x| fs1.contains(x));
    let diff = fs1.difference(&fs2).count();
    return ((p1 < p2) && is_contained) || ((p1 == p2) && is_contained && diff > 0);
}
