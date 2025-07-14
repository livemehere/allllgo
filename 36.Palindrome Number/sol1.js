/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0) return false;
    const str = x.toString();
    const reversedStr = str.split('').reverse().join('');
    return str === reversedStr;
};

console.log(isPalindrome(11211))
