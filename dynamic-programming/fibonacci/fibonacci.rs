fn fibonacci(n: usize) -> u128 {
    let (mut a, mut b) = (0, 1);
    for _ in 0..n {
        (a, b) = (b, a + b)
    }
    a
}
fn main() {
    println!("{}", fibonacci(10));
}
