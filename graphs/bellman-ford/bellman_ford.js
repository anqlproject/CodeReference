function bellmanFord(
    n, edges,
    s) { // Edges [from,to,weight]; throws for reachable negative cycle.
  const d = Array(n).fill(Infinity);
  d[s] = 0;
  for (let i = 1; i < n; i++) {
    let c = false;
    for (const [u, v, w] of edges)
      if (d[u] !== Infinity && d[u] + w < d[v]) {
        d[v] = d[u] + w;
        c = true;
      }
    if (!c)
      break;
  }
  for (const [u, v, w] of edges)
    if (d[u] !== Infinity && d[u] + w < d[v])
      throw Error("reachable negative cycle");
  return d;
}
module.exports = bellmanFord;
if (require.main === module)
  console.log(bellmanFord(3, [ [ 0, 1, 4 ], [ 0, 2, 5 ], [ 1, 2, -2 ] ], 0));
