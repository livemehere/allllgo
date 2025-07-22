impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut cur_sum = 0;
        let mut max_sum = i32::MIN;

        for n in nums.iter() {
            cur_sum = std::cmp::max(cur_sum + *n, *n);
            max_sum = std::cmp::max(max_sum, cur_sum);
        }

        max_sum
    }
}

struct Solution {}
