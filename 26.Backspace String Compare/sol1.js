/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
   let si = 0;
   let ti = 0;
   let sc = s[si];
   let tc = t[ti];
   let sr = ''
   let tr = '';
   
   while(sc || tc){
    if(sc === '#'){
        sr = sr.slice(0,-1);
    }else if(sc){
        sr+=sc;
    }

    if(tc === '#') {
        tr = tr.slice(0,-1);
    } else if(tc){
        tr+=tc;
    }
      

    sc = s[++si];
    tc = t[++ti];
   } 

   return sr === tr; 

};