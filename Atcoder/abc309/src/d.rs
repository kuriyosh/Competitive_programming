use std::collections::VecDeque;

use proconio::input;

fn main() {
    input! {
        n1: usize,
        n2: usize,
        m: usize,
        ab: [(usize, usize); m],
    }

    // ab から連結リストを作成
    let mut graph1 = vec![vec![false; n1]; n1];
    let mut graph2 = vec![vec![false; n2]; n2];
    for (a, b) in ab {
        if a <= n1 && b <= n1 {
            graph1[a - 1][b - 1] = true;
            graph1[b - 1][a - 1] = true;
        }

        if a > n1 && b > n1 {
            graph2[a - 1 - n1][b - 1 - n1] = true;
            graph2[b - 1 - n1][a - 1 - n1] = true;
        }
    }

    // 1 <= u <= n1 で 1 から最短経路がもっと長い u を求める
    let sub_a = bfs(&graph1, 0);
    let a = sub_a[0..n1].iter().max().unwrap();

    // n1 + 1 <= v <= n1 + n2 で n1 + 1 から最短距離が最も長い v を求める
    let sub_b = bfs(&graph2, n2 - 1);
    let b = sub_b[0..n2].iter().max().unwrap();

    println!("{}", a + b + 1);
}

// 隣接行列とスタート地点を与えて最短経路を求める関数
fn bfs(graph: &Vec<Vec<bool>>, start: usize) -> Vec<usize> {
    let n = graph.len();
    let mut dist = vec![n; n];
    let mut queue = VecDeque::new();
    dist[start] = 0;
    queue.push_back(start);
    while let Some(u) = queue.pop_front() {
        for v in 0..n {
            if graph[u][v] && dist[v] == n {
                dist[v] = dist[u] + 1;
                queue.push_back(v);
            }
        }
    }
    dist
}
