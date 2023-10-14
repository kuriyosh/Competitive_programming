use std::collections::HashMap;

use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
        c: [String; h],
    }

    let sheet = c
        .iter()
        .map(|s| s.chars().collect::<Vec<char>>())
        .collect::<Vec<Vec<char>>>();

    let mut memo = vec![vec![true; w]; h];

    for i in 0..h {
        let indeces = find_duplicate_indices(&sheet[i]);
        for (_, indeces) in indeces {
            for j in indeces {
                memo[i][j] = false;
            }
        }
    }

    for i in 0..w {
        let column = sheet.iter().map(|row| row[i]).collect::<Vec<char>>();
        let indeces = find_duplicate_indices(&column);
        for (_, indeces) in indeces {
            for j in indeces {
                memo[j][i] = false;
            }
        }
    }

    let count = memo.iter().flatten().filter(|&&m| m == true).count();

    println!("{}", count);
}

fn find_duplicate_indices<T: Eq + std::hash::Hash + Clone>(arr: &[T]) -> HashMap<T, Vec<usize>> {
    let mut element_indices: HashMap<T, Vec<usize>> = HashMap::new();

    for (index, element) in arr.iter().enumerate() {
        let indices = element_indices.entry(element.clone()).or_insert(vec![]);
        indices.push(index);
    }

    element_indices
        .into_iter()
        .filter(|(_, indices)| indices.len() >= 2)
        .collect()
}
