/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function (image, sr, sc, color) {
  const targetColor = image[sr][sc];
  if (targetColor === color) return image;
  adjacent(sr, sc);
  function adjacent(r, c) {
    if (r < 0 || r >= image.length || c < 0 || c >= image[0].length) return;
    const v = image[r][c];
    if (v !== targetColor) return;
    image[r][c] = color;

    adjacent(r - 1, c);
    adjacent(r, c + 1);
    adjacent(r + 1, c);
    adjacent(r, c - 1);
  }
  return image;
};

console.log(
  floodFill(
    [
      [0, 0, 0],
      [0, 0, 0],
    ],
    0,
    0,
    0
  )
);
