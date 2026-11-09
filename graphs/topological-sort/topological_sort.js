function topologicalSort(g) { // Directed adjacency lists; null means cycle.
  const d = Array(g.length).fill(0);
  for (const row of g)
    for (const v of row)
      d[v]++;
  const q = [];
  d.forEach((x, i) => {
    if (!x)
      q.push(i);
  });
  const out = [];
  for (let i = 0; i < q.length; i++) {
    const u = q[i];
    out.push(u);
    for (const v of g[u])
      if (--d[v] === 0)
        q.push(v);
  }
  return out.length === g.length ? out : null;
}
module.exports = topologicalSort;
if (require.main === module)
  console.log(topologicalSort([ [ 1, 2 ], [ 3 ], [ 3 ], [] ]));
