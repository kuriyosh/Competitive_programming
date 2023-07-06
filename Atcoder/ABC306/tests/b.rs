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
        r"1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    ",
        "13\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"1 0 1 0 1 0 0 0 0 1 0 0 1 1 0 1 1 1 1 0 0 0 1 0 0 1 1 1 1 1 1 0 0 0 0 1 0 1 0 1 0 1 1 1 1 0 0 1 1 0 0 0 0 1 0 1 0 1 0 1 0 0 0 0
        ",
        "766067858140017173\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"1 1 1 0 1 0 0 0 0 1 0 0 1 1 0 1 1 1 1 0 0 0 1 0 0 1 1 1 1 1 1 0 0 0 0 1 0 1 0 1 0 1 1 1 1 0 0 1 1 0 0 0 0 1 0 1 0 1 0 1 0 0 0 1
        ",
        "766067858140017173\n",
    )
}
