fn euclidean_gcd(mut a: i64, mut b: i64) -> i64 {
    a = a.abs();
    b = b.abs();
    while b != 0 {
        (a, b) = (b, a % b)
    }
    a
}
fn main() {
    println!("{}", euclidean_gcd(48, 18));
}
