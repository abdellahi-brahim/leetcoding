/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canMakeArithmeticProgression = function(arr) {
    arr = arr.sort(function(a, b){
        return a - b;
    });
    
    let diff = arr[0]-arr[1];
    
    for(let i = 1; i < arr.length-1; ++i){
        if(arr[i]-arr[i+1] != diff)
            return false;
    }
    
    return true;
};
