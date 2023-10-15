use proconio::input;

fn cond(str1: &str, str2: &str) -> bool {
    if str1 == str2 {
        return true;
    }

    let str1 = str1.chars().collect::<Vec<char>>();
    let str2 = str2.chars().collect::<Vec<char>>();

    let mut diff_index = 0;
    for i in 0..str1.len() {
        if str1.get(i) != str2.get(i) {
            diff_index = i;
            break;
        }
    }

    // 一文字追加
    let is_add = (diff_index..str2.len()).all(|i| str1.get(i) == str2.get(i + 1));
    let is_delete = (diff_index..str2.len()).all(|i| str1.get(i + 1) == str2.get(i));
    let is_replace = (diff_index..(str1.len() - 1)).all(|i| str1.get(i + 1) == str2.get(i + 1));

    return is_add || is_delete || is_replace;
}

fn main() {
    input! {
        n: usize,
        t: String,
        s: [String; n]
    }

    let mut ans: Vec<usize> = vec![];

    for i in 0..n {
        if cond(&t, &s[i]) {
            ans.push(i + 1);
        }
    }

    println!("{}", ans.len());
    println!(
        "{}",
        ans.iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(" ")
    );
}
