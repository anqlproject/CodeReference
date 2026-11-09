function linearSearch(a, x) {
  for (let i = 0; i < a.length; i++)
    if (a[i] === x)
      return i;
  return -1;
}
module.exports = linearSearch;
if (require.main === module)
  console.log(linearSearch([ 4, 2, 7 ], 2));
