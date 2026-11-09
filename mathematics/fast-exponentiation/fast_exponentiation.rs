fn fast_exponentiation(mut b: f64, mut e: i32) -> f64 {
    if e < 0 {
        return 1.0 / fast_exponentiation(b, -e);
    }
    let mut r = 1.0;
    while e > 0 {
        if e & 1 != 0 {
            r *= b
        }
        b *= b;
        e >>= 1
    }
    r
}
fn main() {
    println!("{}", fast_exponentiation(2.0, 10));
}
