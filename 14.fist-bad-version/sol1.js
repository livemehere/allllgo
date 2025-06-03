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
        const arr = Array.from({length:n},(_,i)=> i+1);
        const len = arr.length;
        let latestBadVersion;
        for(let i=len-1;i>=0;i--){
            const version = arr[i];
            if(isBadVersion(version)){
                latestBadVersion = version;
            }else{
                return version + 1;
            }
        }
        return latestBadVersion;
    };
};

const fn = solution((n)=>{ return n >= 4})
console.log(fn(5));
;