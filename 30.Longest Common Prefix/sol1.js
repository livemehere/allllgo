/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let res = '';
    const maxLen = Math.max(...strs.map(str=> str.length));
    for(let i=0;i<maxLen;i++){
        const char = strs[0][i];
        const isDiff = strs.slice(1).some(str => str[i] !== char);
        if(isDiff){
            break;
        }else{
            res+= char;
        }
    }
    return res;
};

console.log(longestCommonPrefix(["flower","flow","flight"]));

