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
        r"4
    0101
    1101
    1111
    0000
    ",
        "1010
1101
0111
0001\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"2
    11
    11",
        "11
11\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"5
        01010
        01001
        10110
        00110
        01010",
        "00101
11000
00111
00110
10100\n",
    )
}
