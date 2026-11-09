function kruskal(n, edges) { // Undirected [u,v,w]; null for disconnected graph.
  const p = Array.from({length : n}, (_, i) => i), r = Array(n).fill(0),
        find = x => p[x] === x ? x : (p[x] = find(p[x]));
  const ordered = edges.map(e => [...e]);
  for (let i = 1; i < ordered.length; i++) {
    const e = ordered[i];
    let j = i;
    while (j > 0 && ordered[j - 1][2] > e[2]) {
      ordered[j] = ordered[j - 1];
      j--;
    }
    ordered[j] = e;
  }
  const chosen = [];
  let total = 0;
  for (const [u, v, w] of ordered) {
    let a = find(u), b = find(v);
    if (a !== b) {
      if (r[a] < r[b])
        [a, b] = [ b, a ];
      p[b] = a;
      if (r[a] === r[b])
        r[a]++;
      chosen.push([ u, v, w ]);
      total += w;
    }
  }
  return chosen.length === Math.max(0, n - 1) ? [ total, chosen ] : null;
}
module.exports = kruskal;
if (require.main === module)
  console.log(kruskal(3, [ [ 0, 1, 4 ], [ 1, 2, 2 ], [ 0, 2, 5 ] ]));
