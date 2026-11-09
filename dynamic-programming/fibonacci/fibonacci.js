function fibonacci(n) {
  if (n < 0)
    throw RangeError("n must be nonnegative");
  let a = 0, b = 1;
  for (let i = 0; i < n; i++)
    [a, b] = [ b, a + b ];
  return a;
}
module.exports = fibonacci;
if (require.main === module)
  console.log(fibonacci(10));
