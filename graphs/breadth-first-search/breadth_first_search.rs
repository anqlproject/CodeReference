// Integer-indexed directed adjacency lists; visits only vertices reachable from start.
use std::collections::VecDeque;
fn bfs(g: &[Vec<usize>], s: usize) -> Vec<usize> {
    let mut seen = vec![false; g.len()];
    let mut q = VecDeque::from([s]);
    let mut o = vec![];
    seen[s] = true;
    while let Some(u) = q.pop_front() {
        o.push(u);
        for &v in &g[u] {
            if !seen[v] {
                seen[v] = true;
                q.push_back(v)
            }
        }
    }
    o
}
fn main() {
    println!("{:?}", bfs(&vec![vec![1, 2], vec![3], vec![3], vec![]], 0));
}
