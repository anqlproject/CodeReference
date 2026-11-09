function euclideanGcd(a, b) {
  a = Math.abs(a);
  b = Math.abs(b);
  while (b)
    [a, b] = [ b, a % b ];
  return a;
}
module.exports = euclideanGcd;
if (require.main === module)
  console.log(euclideanGcd(48, 18));
