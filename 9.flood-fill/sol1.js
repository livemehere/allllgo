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
  const visited = {};
  adjacent(sr, sc, targetColor);
  function adjacent(r, c, v) {
    if (v === targetColor) {
      image[r][c] = color;
    }
    console.log(`visit ${r}-${c}`);
    const top = [r - 1, c];
    const right = [r, c + 1];
    const bottom = [r + 1, c];
    const left = [r, c - 1];
    const sides = [top, right, bottom, left];
    sides.forEach(([r, c]) => {
      let color;
      try {
        color = image[r][c];
        console.log(color, targetColor);
        if (
          color !== undefined &&
          !visited[`${r}${c}`] &&
          color === targetColor
        ) {
          adjacent(r, c, color);
        }
        const key = `${r}${c}`;
        visited[key] = true;
      } catch (e) {}
    });
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
