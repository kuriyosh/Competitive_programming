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
        r"3 2
    red green blue
    blue red
    800 1600 2800",
        "5200\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"3 2
    code queen atcoder
    king queen
    10 1 1",
        "21\n",
    )
}
