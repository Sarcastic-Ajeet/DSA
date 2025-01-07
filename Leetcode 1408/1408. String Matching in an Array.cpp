//Leetcode : https://leetcode.com/problems/string-matching-in-an-array/?envType=daily-question&envId=2025-01-07
// T.C = O(n^2)
// S.C = O(1)

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string>result;
        for(int i = 0;i < n ;i++){
            string word = words[i];
            for(int j = 0; j < n; j++){
                if(i != j && words[j].find(word) != string::npos){
                    result.push_back(word);
                    break;
                }
            }
        }

        return result;
    }
};