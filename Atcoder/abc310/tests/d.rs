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
        r"5 2 2
    1 3
    3 4",
        "4\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"5 1 2
    1 3
    3 4",
        "0\n",
    )
}

#[test]
fn sample3() {
    test_runner(r"6 4 0", "65\n")
}

#[test]
fn sample4() {
    test_runner(r"10 6 8
    5 9
    1 4
    3 8
    1 6
    4 10
    5 7
    5 6
    3 7", "8001\n")
}
