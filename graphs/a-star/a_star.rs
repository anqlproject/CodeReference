// Weighted adjacency lists require nonnegative weights; admissible heuristic estimates remaining cost.
use std::cmp::Reverse;
use std::collections::BinaryHeap;
fn a_star(g: &[Vec<(usize, i64)>], s: usize, t: usize, h: impl Fn(usize) -> i64) -> Option<i64> {
    let mut d = vec![i64::MAX; g.len()];
    d[s] = 0;
    let mut q = BinaryHeap::from([Reverse((h(s), 0, s))]);
    while let Some(Reverse((_, c, u))) = q.pop() {
        if c != d[u] {
            continue;
        }
        if u == t {
            return Some(c);
        }
        for &(v, w) in &g[u] {
            assert!(w >= 0);
            if c + w < d[v] {
                d[v] = c + w;
                q.push(Reverse((c + w + h(v), c + w, v)))
            }
        }
    }
    None
}
fn main() {
    println!(
        "{:?}",
        a_star(
            &vec![vec![(1, 2), (2, 5)], vec![(2, 1)], vec![]],
            0,
            2,
            |_| 0
        )
    );
}
