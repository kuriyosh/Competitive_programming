use cli_test_dir::*;

const BIN: &'static str = "./d";

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
        r"3 4 6
    1 2
    2 3
    4 5
    4 6
    1 3
    6 7",
        "5\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"7 5 20
    10 11
    4 5
    10 12
    1 2
    1 5
    5 6
    2 4
    3 5
    9 10
    2 5
    1 4
    11 12
    9 12
    8 9
    5 7
    3 7
    3 6
    3 4
    8 12
    9 11
    ",
        "4\n",
    )
}
