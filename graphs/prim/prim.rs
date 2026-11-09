// Undirected weighted adjacency lists; returns failure when the graph is disconnected.
fn prim(g: &[Vec<(usize, i64)>], s: usize) -> Option<i64> {
    if g.is_empty() {
        return Some(0);
    }
    let mut seen = vec![false; g.len()];
    seen[s] = true;
    let (mut n, mut sum) = (1, 0);
    while n < g.len() {
        let mut best = None;
        for u in 0..g.len() {
            if seen[u] {
                for &(v, w) in &g[u] {
                    if !seen[v] && best.map_or(true, |x: (usize, usize, i64)| w < x.2) {
                        best = Some((u, v, w))
                    }
                }
            }
        }
        let (_, v, w) = best?;
        seen[v] = true;
        n += 1;
        sum += w
    }
    Some(sum)
}
fn main() {
    println!(
        "{:?}",
        prim(
            &vec![
                vec![(1, 4), (2, 5)],
                vec![(0, 4), (2, 2)],
                vec![(0, 5), (1, 2)]
            ],
            0
        )
    );
}
