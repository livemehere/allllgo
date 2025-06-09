/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let res=0;
    let map = new Map();
    for(const c of s){
        const prev = map.get(c) ?? 0;
        console.log(c,prev);
        if(prev === 1){
            map.delete(c);
            res+=2;
        }else{
            map.set(c,prev+1);
        }
    }

    if(map.size > 0){
        return res+1;
    }else{
        return res;
    }

};

console.log(longestPalindrome('aabbc'));
