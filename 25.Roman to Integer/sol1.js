/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
   const m = {
    "I":1,
    "V":5,
    "X":10,
    "L":50,
    "C":100,
    "D":500,
    "M":1000,
   };
   const subM = {
    "V":"I",
    "X":"I",
    "L":"X",
    "C":"X",
    "D":"C",
    "M":"C",
   };

   let sum=0;
   let subChar;
   for(let i = s.length-1;i>=0;i--){
        const char = s[i];
        const v = m[char];
        if(subChar == char){
            sum-=v;
        }else{
            sum+=v;
        }
        subChar = subM[char];
   } 
   return sum;
};