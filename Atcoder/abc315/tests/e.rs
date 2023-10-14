use cli_test_dir::*;

const BIN: &'static str = "./e";

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
        r"6
    3 2 3 4
    2 3 5
    0
    1 5
    0
    0",
        "5 3 4 2\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"6
    1 2
    1 3
    1 4
    1 5
    1 6
    0",
        "6 5 4 3 2\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"8
        1 5
        1 6
        1 7
        1 8
        0
        0
        0
        0",
        "5\n",
    )
}
