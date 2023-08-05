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
        r"3 5
    xooox
    oooxx
    oooxo",
        "2\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"3 3
    oxo
    oxo
    oxo",
        "1\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"3 3
        oox
        oxo
        xoo",
        "0\n",
    )
}

#[test]
fn sample4() {
    test_runner(
        r"1 7
        ooooooo",
        "7\n",
    )
}

#[test]
fn sample5() {
    test_runner(
        r"5 15
        oxooooooooooooo
        oxooxooooooooox
        oxoooooooooooox
        oxxxooooooxooox
        oxooooooooxooox",
        "5\n",
    )
}
