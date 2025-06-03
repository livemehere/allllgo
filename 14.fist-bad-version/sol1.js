/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        let latestBadVersion;
        let cur = n;
        while(cur !== 0){
            
            if(isBadVersion(cur)){
                latestBadVersion = cur;
            }else{
                return cur + 1;
            }
            cur--;
        }
        return latestBadVersion;
    };
};

const fn = solution((n)=>{ return n >= 4})
console.log(fn(5));