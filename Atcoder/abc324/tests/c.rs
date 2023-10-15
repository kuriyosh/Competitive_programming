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
        r"5 ababc
    ababc
    babc
    abacbc
    abdbc
    abbac",
        "4\n1 2 3 4\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"1 aoki
    takahashi",
        "0\n\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"9 atcoder
        atoder
        atcode
        athqcoder
        atcoder
        tacoder
        jttcoder
        atoder
        atceoder
        atcoer",
        "6\n1 2 4 7 8 9\n",
    )
}
