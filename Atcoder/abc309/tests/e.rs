use cli_test_dir::*;

const BIN: &'static str = "./e";

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
    7 3
1 2 1 3 3 3
1 1
1 2
4 3
",
        "4\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"10 10
    1 1 3 1 2 3 3 5 7
    2 1
    5 1
    4 3
    6 3
    2 1
    7 3
    9 2
    1 2
    6 2
    8 1
    ",
        "10\n",
    )
}
