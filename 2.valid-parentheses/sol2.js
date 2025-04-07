/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  // early return
  if (s.length % 2 !== 0) return false;
  const stack = [];
  const map = {
    "{": "}",
    "(": ")",
    "[": "]",
  };

  // const chars = s.split(""); not required for iterate
  for (const c of s) {
    const pairedChar = map[c];
    if (pairedChar) {
      stack.push(pairedChar);
    } else {
      const expected = stack.pop();
      if (expected !== c) {
        return false;
      }
    }
  }
  //   if (stack.length > 0) return false;
  //   return true;
  return stack.length === 0;
};

console.log(isValid("()")); // true
console.log(isValid("()[]{}")); // true
console.log(isValid("(]")); // false
console.log(isValid("([])")); // false
