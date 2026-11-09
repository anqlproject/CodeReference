function prim(g, s = 0) { // Undirected weighted adjacency lists
                          // [neighbor,weight]; null if disconnected.
  if (!g.length)
    return [ 0, [] ];
  const seen = new Set([ s ]), q = [], chosen = [];
  let total = 0;
  for (const [v, w] of g[s])
    q.push([ w, s, v ]);
  while (q.length && seen.size < g.length) {
    q.sort((a, b) => a[0] - b[0]);
    const [w, u, v] = q.shift();
    if (seen.has(v))
      continue;
    seen.add(v);
    chosen.push([ u, v, w ]);
    total += w;
    for (const [x, c] of g[v])
      if (!seen.has(x))
        q.push([ c, v, x ]);
  }
  return seen.size === g.length ? [ total, chosen ] : null;
}
module.exports = prim;
if (require.main === module)
  console.log(prim([
    [ [ 1, 4 ], [ 2, 5 ] ], [ [ 0, 4 ], [ 2, 2 ] ], [ [ 0, 5 ], [ 1, 2 ] ]
  ]));
