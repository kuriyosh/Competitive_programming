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
    test_runner(r"20230603", "20200000\n")
}

#[test]
fn sample2() {
    test_runner(r"0", "0\n")
}

#[test]
fn sample3() {
    test_runner(r"304", "304\n")
}

#[test]
fn sample4() {
    test_runner(r"500600", "500000\n")
}
