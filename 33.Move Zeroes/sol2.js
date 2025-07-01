/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    
    let left = 0;
    let right = 0;
    while(right < nums.length){

        if(nums[right] != 0){
            swap(nums,left,right);
            left++;
        }

        right++;
    }

    return nums;
};

function swap(arr,a,b){
    let temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}