use proconio::input;

fn main() {
    input! {
        w: i32,
        h: i32,
        n: i32,
        pq: [(i32, i32); n],
        a: i32,
        mut x_lines: [i32; a],
        b: i32,
        mut y_lines: [i32; b],
    }

    x_lines.insert(0, 0);
    x_lines.push(w);

    y_lines.insert(0, 0);
    y_lines.push(h);

    for x in x_lines.windows(2) {
        for y in y_lines.windows(2) {
            for (p, q) in &pq {
                if (x[0] <= *p && p <= &x[1]) && (y[0] <= *q && q <= &y[1]) {}
            }
        }
    }
}
