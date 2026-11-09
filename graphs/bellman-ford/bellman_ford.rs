// Directed weighted edge list; negative weights are allowed; reachable negative cycles are reported.
fn bellman_ford(n: usize, e: &[(usize, usize, i64)], s: usize) -> Option<Vec<Option<i64>>> {
    let mut d = vec![None; n];
    d[s] = Some(0);
    for _ in 1..n {
        let mut c = false;
        for &(u, v, w) in e {
            if let Some(x) = d[u] {
                if d[v].map_or(true, |y| x + w < y) {
                    d[v] = Some(x + w);
                    c = true
                }
            }
        }
        if !c {
            break;
        }
    }
    for &(u, v, w) in e {
        if let Some(x) = d[u] {
            if d[v].map_or(true, |y| x + w < y) {
                return None;
            }
        }
    }
    Some(d)
}
fn main() {
    println!(
        "{:?}",
        bellman_ford(3, &[(0, 1, 4), (0, 2, 5), (1, 2, -2)], 0)
    );
}
