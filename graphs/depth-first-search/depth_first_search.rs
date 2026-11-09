// Integer-indexed directed adjacency lists; visits only vertices reachable from start.
fn dfs(g: &[Vec<usize>], s: usize) -> Vec<usize> {
    let mut seen = vec![false; g.len()];
    let mut st = vec![s];
    let mut o = vec![];
    while let Some(u) = st.pop() {
        if seen[u] {
            continue;
        }
        seen[u] = true;
        o.push(u);
        for &v in g[u].iter().rev() {
            st.push(v)
        }
    }
    o
}
fn main() {
    println!("{:?}", dfs(&vec![vec![1, 2], vec![3], vec![3], vec![]], 0));
}
