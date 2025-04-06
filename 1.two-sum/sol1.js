/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  for (let i = 0; i < nums.length - 1; i++) {
    const v1 = nums[i];
    for (let j = i + 1; j < nums.length; j++) {
      const v2 = nums[j];
      if (v1 + v2 === target) return [i, j];
    }
  }
};
