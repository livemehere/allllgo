/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
  const res = [];
  for(let i=0;i<=n;i++){
    const bin = i.toString(2);
    const matches = bin.match(/1/g);
    res.push(matches?.length ?? 0);
  }
  return res;
};

console.log(countBits(3));
