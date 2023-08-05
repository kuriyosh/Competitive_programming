use std::collections::HashSet;

use proconio::input;
use proconio::marker::Chars;

#[derive(Debug)]
struct State {
    pos: (u8, u8),
    movement: Movement,
}

#[derive(PartialEq, Debug)]
enum Movement {
    Stop,
    Up,
    Down,
    Left,
    Right,
}

fn main() {
    input! {
        n: usize,
        m: usize,
        s: [Chars; n]
    }

    let mut visited = vec![vec![[false, false, false, false, false]; m]; n];

    let current = State {
        pos: (1, 1),
        movement: Movement::Stop,
    };

    dfs(&current, &mut visited, &s);

    let ans: usize = visited
        .iter()
        .map(|x| x.iter().filter(|&y| y.iter().any(|v| v == &true)).count())
        .sum();

    println!("{}", ans);
}

fn dfs(current: &State, visited: &mut Vec<Vec<[bool; 5]>>, tiles: &Vec<Vec<char>>) {
    visited[current.pos.0 as usize][current.pos.1 as usize]
        [get_state_label(&current.movement) as usize] = true;

    let next_states = get_next_state(current, tiles);
    for next_state in next_states {
        if !visited[next_state.pos.0 as usize][next_state.pos.1 as usize]
            [get_state_label(&next_state.movement) as usize]
        {
            dfs(&next_state, visited, tiles);
        }
    }
}

// 現在のポジションと状態から次に遷移できる状態を列挙しておく
fn get_next_state(state: &State, tiles: &Vec<Vec<char>>) -> Vec<State> {
    let mut candidates: Vec<State> = vec![];

    match state.movement {
        Movement::Stop => {
            if tiles[state.pos.0 as usize][(state.pos.1 + 1) as usize] == '.' {
                candidates.push(State {
                    pos: (state.pos.0, state.pos.1 + 1),
                    movement: Movement::Right,
                });
            }
            if tiles[state.pos.0 as usize][(state.pos.1 - 1) as usize] == '.' {
                candidates.push(State {
                    pos: (state.pos.0, state.pos.1 - 1),
                    movement: Movement::Left,
                });
            }
            if tiles[(state.pos.0 - 1) as usize][state.pos.1 as usize] == '.' {
                candidates.push(State {
                    pos: (state.pos.0 - 1, state.pos.1),
                    movement: Movement::Up,
                });
            }
            if tiles[(state.pos.0 + 1) as usize][state.pos.1 as usize] == '.' {
                candidates.push(State {
                    pos: (state.pos.0 + 1, state.pos.1),
                    movement: Movement::Down,
                });
            }
        }
        Movement::Down => {
            if tiles[(state.pos.0 + 1) as usize][state.pos.1 as usize] == '#' {
                candidates.push(State {
                    pos: state.pos,
                    movement: Movement::Stop,
                });
            }
            if tiles[(state.pos.0 + 1) as usize][state.pos.1 as usize] == '.' {
                candidates.push(State {
                    pos: (state.pos.0 + 1, state.pos.1),
                    movement: Movement::Down,
                });
            }
        }
        Movement::Up => {
            if tiles[(state.pos.0 - 1) as usize][state.pos.1 as usize] == '#' {
                candidates.push(State {
                    pos: state.pos,
                    movement: Movement::Stop,
                });
            }
            if tiles[(state.pos.0 - 1) as usize][state.pos.1 as usize] == '.' {
                candidates.push(State {
                    pos: (state.pos.0 - 1, state.pos.1),
                    movement: Movement::Up,
                });
            }
        }
        Movement::Left => {
            if tiles[state.pos.0 as usize][(state.pos.1 - 1) as usize] == '#' {
                candidates.push(State {
                    pos: state.pos,
                    movement: Movement::Stop,
                });
            }
            if tiles[state.pos.0 as usize][(state.pos.1 - 1) as usize] == '.' {
                candidates.push(State {
                    pos: (state.pos.0, state.pos.1 - 1),
                    movement: Movement::Left,
                });
            }
        }
        Movement::Right => {
            if tiles[state.pos.0 as usize][(state.pos.1 + 1) as usize] == '#' {
                candidates.push(State {
                    pos: state.pos,
                    movement: Movement::Stop,
                });
            }
            if tiles[state.pos.0 as usize][(state.pos.1 + 1) as usize] == '.' {
                candidates.push(State {
                    pos: (state.pos.0, state.pos.1 + 1),
                    movement: Movement::Right,
                });
            }
        }
    }

    candidates
}

fn get_state_label(movement: &Movement) -> i32 {
    match movement {
        Movement::Stop => 0,
        Movement::Up => 1,
        Movement::Down => 2,
        Movement::Left => 3,
        Movement::Right => 4,
    }
}
