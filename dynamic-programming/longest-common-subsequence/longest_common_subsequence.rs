// Returns the length of a longest common subsequence.
fn lcs(a: &str, b: &str) -> usize {
    let b: Vec<_> = b.chars().collect();
    let mut d = vec![0; b.len() + 1];
    for x in a.chars() {
        let mut p = 0;
        for j in 1..=b.len() {
            let old = d[j];
            d[j] = if x == b[j - 1] {
                p + 1
            } else {
                d[j].max(d[j - 1])
            };
            p = old
        }
    }
    d[b.len()]
}
fn main() {
    println!("{}", lcs("ABCBDAB", "BDCAB"));
}
