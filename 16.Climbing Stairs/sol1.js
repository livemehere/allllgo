/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n <= 2) return n;

    let first = 1; // n-1
    let second = 2; // n-2
    for(let i=3;i<=n;i++){
        let third = first + second; // n = (n-2) + (n-1)
        first = second;
        second = third;
    }

    return second;
    
};