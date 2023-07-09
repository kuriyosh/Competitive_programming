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
        r"5
    ab
    ccef
    da
    a
    fe
    ",
        "Yes\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"3
    a
    b
    aba
    ",
        "No\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"2
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        ",
        "Yes\n",
    )
}
