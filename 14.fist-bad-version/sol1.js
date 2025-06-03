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
        if(isBadVersion(1)) return 1;

        let latestBad = n;
        let latestGood = 1;
        let left = 1;
        let right = n;
        let mid;
        
        while(left < right){            
            mid = Math.floor((left+right)/2)
            
            if(isBadVersion(mid)){
                // should found good version from previous
                latestBad = mid;
                right = mid;
            }else{
                // should found bad version from after
                latestGood = mid;
                left = mid;
            }
            // found.
            if(latestBad - latestGood <= 1){
                return latestBad;
            }
        }
        return latestBad;
    };
};

const fn = solution((n)=>{ return n == 1})
console.log(fn(3));