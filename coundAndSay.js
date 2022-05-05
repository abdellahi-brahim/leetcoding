/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if(n==1) return "1";
    
    let previousSaying = countAndSay(n-1);
    let saying = "";
    
    for(let i = 0; i < previousSaying.length; ++i){
        let currentNumber = previousSaying[i];
        let count = 1;
        
        while(previousSaying[i+count] == currentNumber){
            count += 1;
        }
        
        saying += count + currentNumber;
        i+=count-1;
    }
    
    return saying;
};
