/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    
    let romanValue = {"M": 1000, 
                        "D": 500,
                        "C": 100,
                        "L": 50, 
                        "X": 10,
                        "V": 5,
                        "I": 1};
    
    value = 0;
    
    for(let i = 0;A i < s.length; ++i){
        if(i < s.length-1 && romanValue[s[i+1]] > romanValue[s[i]]){
            value += romanValue[s[i+1]] - romanValue[s[i]];
            i++;
        }
        else{
            value += romanValue[s[i]];
        }
    }
    
    return value;
};
