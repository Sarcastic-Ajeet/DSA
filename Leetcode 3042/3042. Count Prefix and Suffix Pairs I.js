/**
 * @param {string[]} words
 * @return {number}
 */

function isPrefixAndSuffix(s1 , s2){
    if(s1.length > s2.length) return false;
    let n1 = s1.length - 1
    let n2 = s2.length - 1
    for(let i = 0 ; i <= n1 ;i++ ){
        if(s1[i] != s2[i] || s1[n1 - i] != s2[n2 - i]) return false;
    }

    return true;
}
var countPrefixSuffixPairs = function(words) {
    let result = 0;
    let n = words.length
    for(let i = 0; i < n ; i++){
        for(let j = i+1 ; j < n ; j++){
            if(isPrefixAndSuffix(words[i] , words[j])){
                result += 1;
            }
        }
    }
    return result;
    
};
