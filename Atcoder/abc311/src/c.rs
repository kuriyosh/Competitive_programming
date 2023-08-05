use proconio::input;

fn main() {
    input! {
        n: usize
    }

    let mut graph = vec![vec![]; n];

    for i in 0..n {
        input! {
            a: usize
        }
        graph[i].push(a - 1);
    }

    let mut visited = vec![];
    let mut mark = vec![false; n];
    let mut current = 0;
    while {
        visited.push(current);
        mark[current] = true;
        current = graph[current][0];

        !mark[current]
    } {}

    let start = visited.iter().position(|&x| x == current).unwrap();
    let loop_arr = visited[start..].to_vec();
    println!("{}", loop_arr.len());
    println!(
        "{}",
        loop_arr
            .iter()
            .map(|x| (x + 1).to_string())
            .collect::<Vec<String>>()
            .join(" ")
    );
}
