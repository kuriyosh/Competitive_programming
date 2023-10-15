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
        r"3
    -xx
    o-x
    oo-",
        "3 2 1\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"7
    -oxoxox
    x-xxxox
    oo-xoox
    xoo-ooo
    ooxx-ox
    xxxxx-x
    oooxoo-",
        "4 7 3 1 5 2 6\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"4
    -ooo
    o-oo
    oo-o
    ooo-",
        "1 2 3 4\n",
    )
}

#[test]
fn sample4() {
    test_runner(
        r"10
    -ooooooooo
    o-oooooooo
    oo-ooooooo
    ooo-oooooo
    oooo-ooooo
    ooooo-oooo
    oooooo-ooo
    ooooooo-oo
    oooooooo-o
    ooooooooo-",
        "1 2 3 4 5 6 7 8 9 10\n",
    )
}
