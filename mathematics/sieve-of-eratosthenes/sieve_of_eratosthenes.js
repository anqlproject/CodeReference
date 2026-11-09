function sieveOfEratosthenes(n) {
  if (n < 2)
    return [];
  const p = Array(n + 1).fill(true);
  p[0] = p[1] = false;
  for (let i = 2; i * i <= n; i++)
    if (p[i])
      for (let j = i * i; j <= n; j += i)
        p[j] = false;
  return p.flatMap((x, i) => x ? [ i ] : []);
}
module.exports = sieveOfEratosthenes;
if (require.main === module)
  console.log(sieveOfEratosthenes(30));
