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
        r"4
    4320",
        "2\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"3
    010",
        "2\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"13
        8694027811503",
        "840\n",
    )
}
