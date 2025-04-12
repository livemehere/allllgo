# valid-palindrome

| No  | Approach               | Time Complexity | Space Complexity | Summary                                                                            |
| --- | ---------------------- | --------------- | ---------------- | ---------------------------------------------------------------------------------- |
| 1   | Regex                  | O(n)            | O(n)             | use regex to remove non-alphanumerics and convert to lowercase, then compare.      |
| 2   | Tow Pointer(Optimized) | O(n)            | O(1)             | Traverse from both ends, skipping non-alphanumerics and comparing lowercase chars. |

## comparison

- `js` and `c++` offer nearly identical performance in terms of speed. However, c++ cna be significantly more memory efficient using up to 5 times less memory. Because of direct pointer manipulation and lower-level memory control.

## Performance Comparison

| Language   | Runtime | Memory |
| ---------- | ------- | ------ |
| C++        | 6ms     | 9.8MB  |
| JavaScript | 7ms     | 55.7MB |

## Learn

- newly known about `std::tolower`, `std::isalnum`, `#include <regex>`.
- Avoid using regex for large scale filtering when performance is a concern.
