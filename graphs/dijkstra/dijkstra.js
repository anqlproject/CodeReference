function dijkstra(g, s) { // Weighted adjacency lists [neighbor,weight]; weights
                          // must be nonnegative.
  const d = Array(g.length).fill(Infinity);
  d[s] = 0;
  const q = [ [ 0, s ] ];
  while (q.length) {
    q.sort((a, b) => a[0] - b[0]);
    const [du, u] = q.shift();
    if (du !== d[u])
      continue;
    for (const [v, w] of g[u]) {
      if (w < 0)
        throw Error("negative edge");
      if (du + w < d[v]) {
        d[v] = du + w;
        q.push([ d[v], v ]);
      }
    }
  }
  return d;
}
module.exports = dijkstra;
if (require.main === module)
  console.log(dijkstra([ [ [ 1, 2 ], [ 2, 5 ] ], [ [ 2, 1 ] ], [] ], 0));
