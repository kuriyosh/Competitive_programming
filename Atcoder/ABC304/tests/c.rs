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
        r"4 5
    2 -1
    3 1
    8 8
    0 5",
        "Yes
Yes
No
Yes\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"3 1
        0 0
        -1000 -1000
        1000 1000",
        "Yes
No
No\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"9 4
        3 2
        6 -1
        1 6
        6 5
        -2 -3
        5 3
        2 -3
        2 1
        2 6",
        "Yes
No
No
Yes
Yes
Yes
Yes
Yes
No\n",
    )
}
