/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function(n) {
    const bit = n.toString(2);
    return bit.split('1').length - 1;
};

console.log(hammingWeight(11));
