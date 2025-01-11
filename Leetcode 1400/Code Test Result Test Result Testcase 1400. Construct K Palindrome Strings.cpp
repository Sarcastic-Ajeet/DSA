/************************************************************CPP********************************************/
// T.C = O(n)
// S.C = O(26)
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        vector<int>mp(26, 0);
        for(auto ch : s){
            mp[ch - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26 ; i++){
            if(mp[i]&1) count++;
        }
        if(count > k) return false;
        return true;
    }
};


/************************************************************JavaScript********************************************/
/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    if(s.length < k) return false
    let arr = new Array(26).fill(0)
    for(let i = 0; i < s.length ; i++){
        arr[s.charCodeAt(i) - 'a'.charCodeAt(0)]++
    }

    let count = 0;
    for(let i = 0 ;i < 26 ; i++){
        if(arr[i] &1) count++
    }
    if(count > k) return false
    return true
    
};
