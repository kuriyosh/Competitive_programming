use cli_test_dir::*;

const BIN: &'static str = "./b";

fn test_runner(input: &str, expected: &str) {
    let test_dir = TestDir::new(BIN, "");
    let output = test_dir
        .cmd()
        .output_with_stdin(input)
        .tee_output()
        .expect_success();
    assert_eq!(output.stdout_str(), expected);
    assert!(output.stderr_str().is_empty());
}

#[test]
fn sample1() {
    test_runner(
        r"5 6
    10000 2 1 3
    15000 3 1 2 4
    30000 3 1 3 5
    35000 2 1 5
    100000 6 1 2 3 4 5 6",
        "Yes\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"4 4
    3 1 1
    3 1 2
    3 1 2
    4 2 2 3",
        "No\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"20 10
        72036 3 3 4 9
        7716 4 1 2 3 6
        54093 5 1 6 7 8 10
        25517 7 3 4 5 6 7 9 10
        96930 8 2 3 4 6 7 8 9 10
        47774 6 2 4 5 6 7 9
        36959 5 1 3 4 5 8
        46622 7 1 2 3 5 6 8 10
        34315 9 1 3 4 5 6 7 8 9 10
        54129 7 1 3 4 6 7 8 9
        4274 5 2 4 7 9 10
        16578 5 2 3 6 7 9
        61809 4 1 2 4 5
        1659 5 3 5 6 9 10
        59183 5 1 2 3 4 9
        22186 4 3 5 6 8
        98282 4 1 4 7 10
        72865 8 1 2 3 4 6 8 9 10
        33796 6 1 3 5 7 9 10
        74670 4 1 2 6 8",
        "Yes\n",
    )
}
