// Directed adjacency lists; returns no ordering when a directed cycle exists.
use std::collections::VecDeque;
fn topological_sort(g: &[Vec<usize>]) -> Option<Vec<usize>> {
    let mut d = vec![0; g.len()];
    for r in g {
        for &v in r {
            d[v] += 1
        }
    }
    let mut q: VecDeque<_> = d
        .iter()
        .enumerate()
        .filter(|x| *x.1 == 0)
        .map(|x| x.0)
        .collect();
    let mut o = vec![];
    while let Some(u) = q.pop_front() {
        o.push(u);
        for &v in &g[u] {
            d[v] -= 1;
            if d[v] == 0 {
                q.push_back(v)
            }
        }
    }
    if o.len() == g.len() {
        Some(o)
    } else {
        None
    }
}
fn main() {
    println!(
        "{:?}",
        topological_sort(&vec![vec![1, 2], vec![3], vec![3], vec![]])
    );
}
