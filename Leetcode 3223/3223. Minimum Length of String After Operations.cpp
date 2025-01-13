// Leetcode : https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13
/******************************************** CPP ******************************************/
// T.C = O(n)
// S.C = O(26)

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length(), result = 0;
        vector<int>mp(26,0);
        for(int i = 0; i < n ; i++){
            mp[s[i] - 'a']++;
            if(mp[s[i] - 'a'] == 3){
                result += 2;
                mp[s[i] - 'a'] -= 2;
            }
        }
        return n - result;
        
    }
};


/******************************************** JavaScript ******************************************/
// T.C = O(n)
// S.C = O(26)

/**
 * @param {string} s
 * @return {number}
 */
var minimumLength = function(s) {
    let n = s.length , result = 0
    arr = new Array(26).fill(0)

    for(let i = 0; i < n ; i++){
        arr[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        if(arr[s.charCodeAt(i) - 'a'.charCodeAt(0)] === 3){
            result += 2;
            arr[s.charCodeAt(i) - 'a'.charCodeAt(0)] -= 2;
        }
    }
    return n - result;
    
};
