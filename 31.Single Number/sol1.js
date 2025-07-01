/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  const m = new Map();
  for(const n of nums){
    const v = m.get(n);
    // first
    if(v == undefined){
        m.set(n,1);
        continue;
    }
    // second times
    // remove n from arr
    if(v == 1){
        m.delete(n);
    }
  }  
  return m.keys().next().value;
};