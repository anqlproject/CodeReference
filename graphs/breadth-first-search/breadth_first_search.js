function breadthFirstSearch(
    g, s) { // Integer adjacency lists; reachable vertices only.
  const seen = new Set([ s ]), q = [ s ], out = [];
  for (let i = 0; i < q.length; i++) {
    const u = q[i];
    out.push(u);
    for (const v of g[u])
      if (!seen.has(v)) {
        seen.add(v);
        q.push(v);
      }
  }
  return out;
}
module.exports = breadthFirstSearch;
if (require.main === module)
  console.log(breadthFirstSearch([ [ 1, 2 ], [ 3 ], [ 3 ], [] ], 0));
