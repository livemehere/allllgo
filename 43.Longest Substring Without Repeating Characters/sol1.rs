use std::cmp::max;
use std::collections::{HashSet, VecDeque};

struct Solution {}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut result = 0;
        let mut window: VecDeque<char> = VecDeque::new();
        let mut seen: HashSet<char> = HashSet::new();

        for c in s.chars() {
            if seen.contains(&c) {
                result = max(result, window.len());
                while let Some(v) = window.pop_front() {
                    seen.remove(&v);
                    if v == c {
                        break;
                    }
                }
            }
            window.push_back(c);
            seen.insert(c);
        }

        result = max(result, window.len());
        result as i32
    }
}
fn main() {
    println!(
        "{}",
        Solution::length_of_longest_substring(String::from("aab"))
    );
}
