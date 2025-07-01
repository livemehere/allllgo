/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let sum = 0;
    for(const n of nums){
        sum+=n;
    }
    return sumToN(nums.length) - sum;
    
};

function sumToN(n){
    if(n===0) return 0;
    if(n===1) return 1;
    return n + sumToN(n-1);
}