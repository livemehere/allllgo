# Merge Two Sorted Lists

| No  | Approach  | Time Complexity | Space Complexity | Summary                                       |
| --- | --------- | --------------- | ---------------- | --------------------------------------------- |
| 1   | Iterative | O(n+m)          | O(1)             | Iterate through both lists and merge in-place |
| 2   | Recursive | O(n+m)          | O(n+m)           | Recursively merge the lists                   |

## comparison

- C++ implementation uses less `memory`

![alt text](cpp.png)

![alt text](js.png)

## Learn

- `c++` has two type of `null`. `NULL` is a macro that expands to `0`, `nullptr` is a keyword that represents a null pointer constant.
- `nullptr` is type-safe and can be used in any context where a pointer is expected while `NULL` is an integer constant that can be implicitly converted to any pointer type.
