//Leetcode : https://leetcode.com/problems/string-matching-in-an-array/?envType=daily-question&envId=2025-01-07
// T.C = O(n^2)
// S.C = O(1)

/**
 * @param {string[]} words
 * @return {string[]}
 */
var stringMatching = function(words) {
    let n = words.length;
    let result = new Array();
    for(let i = 0; i < n ; i++){
        let word = words[i];
        for(let j = 0; j < n ; j++){
            if(i != j && words[j].indexOf(word) != -1){
                result.push(word);
                break;
            }
        }
    }
    return result;
};