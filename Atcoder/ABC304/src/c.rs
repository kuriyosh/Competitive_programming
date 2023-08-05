use proconio::input;

fn main() {
    input! {
        n: usize,
        d: f64,
    }

    let mut infected = vec![false; n];
    infected[0] = true;
    let mut points = Vec::<(usize, usize)>::new();

    for i in 0..n {
        input! {
            x: usize,
            y: usize,
        }

        for j in 0..i {
            if infected[j] && get_distance(points[j], (x, y)) <= d {
                infected[i] = true;
                break;
            }
        }

        points.push((x, y));
    }
}

fn get_distance((x1, y1): (usize, usize), (x2, y2): (usize, usize)) -> f64 {
    let a = ((x1 - x2).pow(2) + (y1 - y2).pow(2)) as f64;
    return a.sqrt();
}
