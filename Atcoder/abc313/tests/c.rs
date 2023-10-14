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
        r"
    4
4 7 3 7",
        "3\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"1
    313",
        "0\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"10
        999999997 999999999 4 3 2 4 999999990 8 999999991 999999993",
        "2499999974\n",
    )
}
