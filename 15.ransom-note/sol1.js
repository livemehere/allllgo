/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    const m = new Map();
    [].forEach.call(magazine, c => {
        m.set(c, (m.get(c) ?? 0)+1);
    })
    return [].every.call(ransomNote, c=>{
        const rest = (m.get(c) ?? 0) - 1;
        if(rest < 0) return false;
        m.set(c,rest);
        return true;
    })
};

console.log(canConstruct("aa","ab"));