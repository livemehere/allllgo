/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = [];
  const map = {
    "{": "}",
    "(": ")",
    "[": "]",
  };
  const chars = s.split("");
  for (const c of chars) {
    const closeChar = map[c];
    if (closeChar) {
      stack.push(closeChar);
    } else {
      const closeChar = stack.pop();
      if (closeChar !== c) {
        return false;
      }
    }
  }
  if (stack.length > 0) return false;
  return true;
};

console.log(isValid("()")); // true
console.log(isValid("()[]{}")); // true
console.log(isValid("(]")); // false
console.log(isValid("([])")); // false
