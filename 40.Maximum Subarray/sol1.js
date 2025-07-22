/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let curSum = 0;
    let maxSum = Number.MIN_SAFE_INTEGER;
    for(const n of nums) {
        curSum = Math.max(n, curSum+n);
        maxSum = Math.max(maxSum, curSum);
    }  
    return maxSum;
};