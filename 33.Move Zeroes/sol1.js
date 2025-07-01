/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let cnt = 0;
    let i=0;
    while(i < nums.length){
        const n = nums[i];
        if(n === 0) {
            cnt++;
            nums.splice(i,1);
        }else{
            i++;
        }
    }
    const zeros = Array.from({length:cnt},()=>0);
    nums.splice(nums.length,0,...zeros)
    return nums;
};