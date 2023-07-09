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
        r"2
    1000 2000 3000 4000 5000 6000 7000 2000 3000 4000 5000 6000 7000 8000",
        "28000 35000\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"3
    14159 26535 89793 23846 26433 83279 50288 41971 69399 37510 58209 74944 59230 78164 6286 20899 86280 34825 34211 70679 82148",
        "314333 419427 335328\n",
    )
}
