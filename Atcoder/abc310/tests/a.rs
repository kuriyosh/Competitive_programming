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
    test_runner(
        r"3 100 50
    60 20 40",
        "70\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"3 100 50
60000 20000 40000",
        "100\n",
    )
}
