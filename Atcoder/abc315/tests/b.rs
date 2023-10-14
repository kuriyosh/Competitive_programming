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
        r"12
    31 28 31 30 31 30 31 31 30 31 30 31
    ",
        "7 2\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"1
    1", "1 1\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"6
        3 1 4 1 5 9",
        "5 3\n",
    )
}
