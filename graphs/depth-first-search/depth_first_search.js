function depthFirstSearch(
    g, s) { // Integer adjacency lists; reachable vertices only.
  const seen = new Set(), out = [], st = [ s ];
  while (st.length) {
    const u = st.pop();
    if (seen.has(u))
      continue;
    seen.add(u);
    out.push(u);
    for (let i = g[u].length - 1; i >= 0; i--)
      st.push(g[u][i]);
  }
  return out;
}
module.exports = depthFirstSearch;
if (require.main === module)
  console.log(depthFirstSearch([ [ 1, 2 ], [ 3 ], [ 3 ], [] ], 0));
