# My AtCoder template for Rust

## Usage

1. Pull this template with [cargo generate](https://github.com/cargo-generate/cargo-generate)

   ```console
   cargo generate --git https://github.com/kuriyosh/atcoder-template
   ```

2. Copy sample input/output for each unit test
3. Run unit test with [cargo watch](https://github.com/watchexec/cargo-watch)

   ```console
   cargo watch -x 'test --test a'
   ```

4. (optional) Comment out package names which you want to use in `Cargo.toml`
