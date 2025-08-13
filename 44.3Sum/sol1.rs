impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let mut res: Vec<Vec<i32>> = Vec::new();
        let n = nums.len();

        for i in 0..n {
            /* 첫 중복값 스킵 */
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }

            let mut l = i + 1;
            let mut r = n - 1;

            while l < r {
                let sum = nums[i] + nums[l] + nums[r];
                if sum == 0 {
                    /* 케이스 추가 */
                    res.push(vec![nums[i], nums[l], nums[r]]);

                    /* 각 다음 인덱스 중복값 스킵(정렬했기 때문에 가능) */
                    while l < r && nums[l] == nums[l + 1] {
                        l += 1;
                    }

                    while l < r && nums[r] == nums[r - 1] {
                        r -= 1;
                    }
                    l += 1;
                    r -= 1;
                } else if sum < 0 {
                    l += 1;
                } else {
                    r -= 1;
                }
            }
        }

        res
    }
}
