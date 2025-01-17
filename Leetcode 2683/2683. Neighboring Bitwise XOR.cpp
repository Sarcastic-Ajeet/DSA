/*********************************** CPP ******************************/
// T.C = O(n)
// S.C = O(1)

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result = 0;
        for(int  i = 0 ;i < derived.size() ; i++){
            result ^= derived[i];
        }
        if(result == 0) return true;
        return false;
    }
};

/*********************************** JavaScript ******************************/

/**
 * @param {number[]} derived
 * @return {boolean}
 */
var doesValidArrayExist = function(derived) {
    let result = 0;
    derived.forEach((num) => (result ^= num))

    if(result == 0) return true;

    return false
    
};
