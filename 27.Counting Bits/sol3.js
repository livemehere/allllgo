/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
  const res = [];
  for(let i=0;i<=n;i++){
    const bin = i.toString(2);
    let sum = 0;
    for(const c of bin){
      if(c == '1') sum++;
    }
    res.push(sum);
  }
  return res;
};

console.log(countBits(3));
