// Leetcode : https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05
// T.C = O(m + n) m = length of s , n = size of query
// S.C = O(m)

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int>str(n , 0);

        for(auto shift : shifts){
            if(shift[2] == 1){
                str[shift[0]] += 1;
                if(shift[1] +1 < n) str[shift[1] + 1] -= 1;
            }else{
                str[shift[0]] -= 1;
                if(shift[1] +1 < n) str[shift[1] + 1] += 1;
                
            }
        }
         
        for(int i = 1; i < n ;i++){
            str[i] += str[i-1];
        }

        for(int i = 0; i < n; i++){
            str[i] = (str[i] % 26) < 0 ? 26 + (str[i] % 26) : (str[i] % 26);
            s[i] = (s[i] - 'a' + str[i]) %26 + 'a';
            
        }

        return s;
    }

};