/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  if (s.length !== t.length) return false;
  const cache = new Map();
  for (const c of s) {
    cache.set(c, (cache.get(c) || 0) + 1);
  }
  for (const c of t) {
    if (cache.has(c) && cache.get(c) > 0) {
      cache.set(c, cache.get(c) - 1);
    } else {
      return false;
    }
  }
  return true;
};
