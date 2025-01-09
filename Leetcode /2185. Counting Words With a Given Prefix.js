/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function(words, pref) {
    let  result = 0
    for(let i = 0; i < words.length; i++){
        if(words[i].indexOf(pref) == 0) result++;
    }
    return result;
};
