// Weighted adjacency lists; edge weights must be nonnegative.
use std::cmp::Reverse;
use std::collections::BinaryHeap;
fn dijkstra(g: &[Vec<(usize, i64)>], s: usize) -> Vec<Option<i64>> {
    let mut d = vec![None; g.len()];
    d[s] = Some(0);
    let mut q = BinaryHeap::from([Reverse((0, s))]);
    while let Some(Reverse((du, u))) = q.pop() {
        if d[u] != Some(du) {
            continue;
        }
        for &(v, w) in &g[u] {
            assert!(w >= 0);
            let nd = du + w;
            if d[v].map_or(true, |x| nd < x) {
                d[v] = Some(nd);
                q.push(Reverse((nd, v)))
            }
        }
    }
    d
}
fn main() {
    println!(
        "{:?}",
        dijkstra(&vec![vec![(1, 2), (2, 5)], vec![(2, 1)], vec![]], 0)
    );
}
