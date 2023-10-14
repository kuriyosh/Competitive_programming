use proconio::input;

fn main() {
    input! {
        n: usize,
        m: usize,
    }

    let mut graph = vec![vec![false; n]; n];
    for _ in 0..m {
        input! {
            a: usize,
            b: usize,
        }
        graph[b - 1][a - 1] = true;
    }

    let mut cand: i32 = -1;
    for i in 0..n {
        let mut visited = vec![false; n];
        let check = traverse(i, &graph, &mut visited);
        if cand == -1 {
            cand = check as i32;
        } else if cand != check as i32 {
            println!("-1");
            return;
        }
    }
    println!("{}", cand + 1);
}

fn traverse(current: usize, graph: &Vec<Vec<bool>>, visited: &mut Vec<bool>) -> i32 {
    visited[current] = true;
    for i in 0..graph[current].len() {
        if graph[current][i] && visited[i] != true {
            return traverse(i, graph, visited);
        }
    }
    current as i32
}
