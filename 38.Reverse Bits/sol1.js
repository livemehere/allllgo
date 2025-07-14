/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
  const s = n.toString(2).padStart(32,'0').split('').reverse().join('');
  return parseInt(s, 2)
};

console.log(reverseBits(4));
