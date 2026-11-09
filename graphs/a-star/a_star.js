function aStar(g, s, goal,
               h) { // Weighted adjacency lists; nonnegative weights; admissible
                    // h(node) estimates remaining cost.
  const best = Array(g.length).fill(Infinity), open = [ [ h(s), 0, s ] ];
  best[s] = 0;
  while (open.length) {
    open.sort((a, b) => a[0] - b[0]);
    const [f, c, u] = open.shift();
    if (c !== best[u])
      continue;
    if (u === goal)
      return c;
    for (const [v, w] of g[u]) {
      if (w < 0)
        throw Error("negative edge");
      if (c + w < best[v]) {
        best[v] = c + w;
        open.push([ c + w + h(v), c + w, v ]);
      }
    }
  }
  return null;
}
module.exports = aStar;
if (require.main === module)
  console.log(
      aStar([ [ [ 1, 2 ], [ 2, 5 ] ], [ [ 2, 1 ] ], [] ], 0, 2, () => 0));
