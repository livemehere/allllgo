/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
  const res = [];
  for(let i=0;i<=n;i++){
    const bin = i.toString(2);
    const n = bin.split('1').length - 1;
    res.push(n);
  }
  return res;
};

console.log(countBits(3));
