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
        r"5
    alice 31
    bob 41
    carol 5
    dave 92
    ellen 65",
        "carol
dave
ellen
alice
bob\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"2
    takahashi 1000000000
    aoki 999999999",
        "aoki
takahashi\n",
    )
}
