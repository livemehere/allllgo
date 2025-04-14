# Binary Search

| No  | Approach | Time Complexity | Space Complexity | Summary                                 |
| --- | -------- | --------------- | ---------------- | --------------------------------------- |
| 1   | DFS      | O(n)            | O(n)             | Recursively visit each cell in the grid |

## comparison

- c++ implementation uses less `memory`

## Performance Comparison

| Language   | Runtime | Memory |
| ---------- | ------- | ------ |
| C++        | 0ms     | 18.1MB |
| JavaScript | 0ms     | 59.3MB |

## Learn

- `try...catch` make code slower.
- visiting check must be before go into recursion.
- visiting check unnecessary, because already check if same color with `startColor`. if it was modified, it will not same as `startColor`.
