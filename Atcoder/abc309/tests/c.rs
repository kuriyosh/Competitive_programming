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
        r"4 8
    6 3
    2 5
    1 9
    4 2
    ",
        "3\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"4 100
    6 3
    2 5
    1 9
    4 2
    ",
        "1\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"15 158260522
        877914575 2436426
        24979445 61648772
        623690081 33933447
        476190629 62703497
        211047202 71407775
        628894325 31963982
        822804784 50968417
        430302156 82631932
        161735902 80895728
        923078537 7723857
        189330739 10286918
        802329211 4539679
        303238506 17063340
        492686568 73361868
        125660016 50287940
        ",
        "492686569\n",
    )
}
