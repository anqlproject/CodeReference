fn sieve(n: usize) -> Vec<usize> {
    if n < 2 {
        return vec![];
    }
    let mut p = vec![true; n + 1];
    p[0] = false;
    p[1] = false;
    for i in 2..=((n as f64).sqrt() as usize) {
        if p[i] {
            for j in (i * i..=n).step_by(i) {
                p[j] = false
            }
        }
    }
    (2..=n).filter(|&i| p[i]).collect()
}
fn main() {
    println!("{:?}", sieve(30));
}
