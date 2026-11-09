// Undirected weighted edge list; returns failure when the graph is disconnected.
fn kruskal(n: usize, e: &mut [(usize, usize, i64)]) -> Option<i64> {
    for i in 1..e.len() {
        let x = e[i];
        let mut j = i;
        while j > 0 && e[j - 1].2 > x.2 {
            e[j] = e[j - 1];
            j -= 1
        }
        e[j] = x
    }
    let mut p: Vec<_> = (0..n).collect();
    fn f(p: &mut [usize], x: usize) -> usize {
        if p[x] != x {
            p[x] = f(p, p[x])
        }
        p[x]
    }
    let (mut sum, mut k) = (0, 0);
    for &(u, v, w) in e.iter() {
        let (a, b) = (f(&mut p, u), f(&mut p, v));
        if a != b {
            p[a] = b;
            sum += w;
            k += 1
        }
    }
    if k == n.saturating_sub(1) {
        Some(sum)
    } else {
        None
    }
}
fn main() {
    println!("{:?}", kruskal(3, &mut [(0, 1, 4), (1, 2, 2), (0, 2, 5)]));
}
