use cli_test_dir::*;

const BIN: &'static str = "./a";

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
    test_runner(r"125 175 250 300 400 525 600 650", "Yes\n")
}

#[test]
fn sample2() {
    test_runner(r"100 250 300 400 325 575 625 675", "No\n")
}

#[test]
fn sample3() {
    test_runner(r"0 23 24 145 301 413 631 632", "No\n")
}
