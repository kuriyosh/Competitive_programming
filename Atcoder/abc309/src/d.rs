use proconio::input;
use std::collections::VecDeque;

// RE/TLE するけど原因わからん

fn main() {
    input! {
        n1: usize,
        n2: usize,
        m: usize,
        ab: [(usize, usize); m],
    }

    // ab から連結リストを作成
    let mut graph: Vec<Vec<bool>> = vec![vec![false; n1 + n2]; n1 + n2];
    for (a, b) in ab {
        graph[a - 1][b - 1] = true;
        graph[b - 1][a - 1] = true;
    }

    // 1 <= u <= n1 で 1 から最短経路がもっと長い u を求める
    let sub_a = bfs(&graph, 0);
    let a = sub_a[0..(n1 + n2)].iter().max().unwrap();

    // n1 + 1 <= v <= n1 + n2 で n1 + 1 から最短距離が最も長い v を求める
    let sub_b = bfs(&graph, n1 + n2 - 1);
    let b = sub_b[0..(n1 + n2)].iter().max().unwrap();

    println!("{}", a + b + 1);
}

// 隣接行列とスタート地点を与えて幅優先で最短経路を求める
fn bfs(graph: &Vec<Vec<bool>>, start: usize) -> Vec<i32> {
    let mut dist: Vec<i32> = vec![-1; graph.len()];

    let mut queue = VecDeque::<usize>::new();
    dist[start] = 0;
    queue.push_back(start);

    while queue.len() > 0 {
        let v = queue.pop_front().unwrap();
        for i in 0..graph.len() {
            if graph[v][i] && dist[i] == -1 {
                dist[i] = dist[v] + 1;
                queue.push_back(i);
            }
        }
    }

    dist
}
