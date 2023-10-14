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
        r"3 2
    1 2
    2 3",
        "1\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"3 2
    1 3
    2 3",
        "-1\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"6 6
        1 6
        6 5
        6 2
        2 3
        4 3
        4 2",
        "-1\n",
    )
}
