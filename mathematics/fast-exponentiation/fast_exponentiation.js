function fastExponentiation(base, exponent) {
  if (exponent < 0)
    return 1 / fastExponentiation(base, -exponent);
  let r = 1;
  while (exponent) {
    if (exponent % 2)
      r *= base;
    base *= base;
    exponent = Math.floor(exponent / 2);
  }
  return r;
}
module.exports = fastExponentiation;
if (require.main === module)
  console.log(fastExponentiation(2, 10));
