/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let i = a.length - 1;
    let j = b.length - 1;
    let carry = 0;
    const res = [];

    while(i>=0 || j>=0 || carry > 0){
        let bitA = i>=0 ? parseInt(a[i]) : 0;
        let bitB = j>=0 ? parseInt(b[j]) : 0;
        const sum = bitA + bitB + carry;
        res.push(sum%2);
        carry = Math.floor(sum/2);
        i--;
        j--;
    }
    return res.reverse().join('');
};