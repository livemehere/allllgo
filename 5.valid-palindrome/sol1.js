/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  s = s.toLowerCase();
  s = s.replace(/[^\w]|_/g, "");
  const n = s.length;
  let result = true;
  for (let i = 0; i < Math.floor(n / 2); i++) {
    const frontChar = s[i];
    const backChar = s[n - (i + 1)];
    if (frontChar !== backChar) {
      result = false;
      break;
    }
  }
  return result;
};
