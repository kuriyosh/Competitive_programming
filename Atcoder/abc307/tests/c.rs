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
        r"3 5
    #.#..
    .....
    .#...
    2 2
    #.
    .#
    5 3
    ...
    #.#
    .#.
    .#.
    ...",
        "Yes\n",
    )
}

#[test]
fn sample2() {
    test_runner(
        r"2 2
    #.
    .#
    2 2
    #.
    .#
    2 2
    ##
    ##",
        "No\n",
    )
}

#[test]
fn sample3() {
    test_runner(
        r"1 1
        #
        1 2
        ##
        1 1
        #",
        "No\n",
    )
}

#[test]
fn sample4() {
    test_runner(
        r"3 3
        ###
        ...
        ...
        3 3
        #..
        #..
        #..
        3 3
        ..#
        ..#
        ###",
        "Yes\n",
    )
}
