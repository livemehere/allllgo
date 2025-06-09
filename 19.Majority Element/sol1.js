/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    const v = nums.length/2;
    const m = new Map();
    for(const n of nums){
        const _v = m.get(n) ?? 1;
        if(_v > v) return n;
        m.set(n,_v+1);
    }
};