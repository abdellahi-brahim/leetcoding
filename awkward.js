/**
 * @param {string} s
 * @return {number}
 */
var minimumLength = function(s) {
    while(s.length > 0){
        if(s.length == 1 || s[0] != s[s.length-1]){
            break;
        }
        
        let character = s[0];
        let prefixIndex = 1;
        
        for(;prefixIndex < s.length; ++prefixIndex){
            if(character != s[prefixIndex]){
                break;
            }
        }
        
        //console.log(s);
        s = s.slice(prefixIndex, s.length);
        //console.log(`${' '.repeat(prefixIndex)}`+s);
        
        let suffixIndex = s.length-2;
        
        for(;suffixIndex>0;--suffixIndex){
            if(character!=s[suffixIndex]){
                break;
            }
        }
        
        //console.log(s);
        s = s.slice(0, suffixIndex+1);
        //console.log(s);
    }
    
    return s.length;
};
