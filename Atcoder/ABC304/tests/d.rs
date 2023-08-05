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
        r"7 6
    5
    6 1
    3 1
    4 2
    1 5
    6 2
    2
    2 5
    2
    3 4",
        "0 2\n",
    )
}

#[test]
fn sample2() {
    test_runner(r"7 6
    5
    6 1
    3 1
    4 2
    1 5
    6 2
    2
    2 5
    2
    3 4", "1 1\n")
}
