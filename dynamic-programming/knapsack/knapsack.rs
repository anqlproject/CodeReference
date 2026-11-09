// 0/1 knapsack contract: weights and capacity are nonnegative; returns maximum value.
fn knapsack(w: &[usize], v: &[i64], c: usize) -> i64 {
    let mut d = vec![0; c + 1];
    for (&x, &y) in w.iter().zip(v) {
        for j in (x..=c).rev() {
            d[j] = d[j].max(d[j - x] + y)
        }
    }
    d[c]
}
fn main() {
    println!("{}", knapsack(&[2, 3, 4], &[4, 5, 6], 5));
}
