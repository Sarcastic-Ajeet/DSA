class Solution {
public:
    bool isPrefixAndSuffix(string &s1 , string &s2){
        if(s1.length() > s2.length()) return 0;
        int n1 = s1.size()-1 , n2 = s2.size() - 1;
        
        for(int i = 0;i < s1.size() ; i++){
            if(s1[i] != s2[i] || s1[n1 - i] != s2[n2 - i]) return 0;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int result = 0 , n = words.size();
        for(int i = 0;i < n ; i++){
            for(int j = i+1; j < n ; j++){
                
                result += isPrefixAndSuffix(words[i] , words[j]);
            }
        }
        return result;
    }
};
