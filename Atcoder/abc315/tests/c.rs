use cli_test_dir::*;

const BIN: &'static str = "./c";

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
        r"4
    1 4
    2 10
    2 8
    3 6",
        "16\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"4
    4 10
    3 2
    2 4
    4 12",
        "17\n",
    )
}
