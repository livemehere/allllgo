/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let res = [];
    let [newStart,newEnd] = newInterval;
    let merged = false;

    for(let i=0;i<intervals.length;i++){
        const curInterval = intervals[i];
        const [curStart,curEnd]=curInterval;

        // 현재 범위가, 신규 범위보다 작을 때 = 넘어감.
        if(curEnd < newStart){ // [n,n, ... [] ,]
            res.push(curInterval);
        }else if (curStart > newEnd){ // 현재 범위가, 신규 범위와 겹치지 않고, 더 클 때 
            if(!merged){
                res.push([newStart,newEnd]);    
                merged = true;
            }
            res.push(curInterval);
        }else{
            // 구간이 겹칠떄
            newStart = Math.min(curStart, newStart);
            newEnd = Math.max(curEnd, newEnd);
        }
  

    }
       if(!merged){
            res.push([newStart, newEnd]);
        }   
    return res;
};