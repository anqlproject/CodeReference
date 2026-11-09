function longestCommonSubsequence(a, b) { // Returns LCS length.
  const d = Array(b.length + 1).fill(0);
  for (const x of a) {
    let prev = 0;
    for (let j = 1; j <= b.length; j++) {
      const old = d[j];
      d[j] = x === b[j - 1] ? prev + 1 : Math.max(d[j], d[j - 1]);
      prev = old;
    }
  }
  return d[b.length];
}
module.exports = longestCommonSubsequence;
if (require.main === module)
  console.log(longestCommonSubsequence("ABCBDAB", "BDCAB"));
