// Leetcode : https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02

// T.C = O(n)
// S.c = O(n)

class Solution {
public:
    int solve(string &str) {
        int n = str.length();
        if (n == 0) return 0; 
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        return isVowel(str[0]) && isVowel(str[n - 1]) ? 1 : 0;
    }

    int countV(int l, int r, vector<int>& vowel) {
        if (l == 0) return vowel[r];
        return vowel[r] - vowel[l - 1];
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> Vowel(n, 0);

        for (int i = 0; i < n; i++) {
            int ans = solve(words[i]);
            Vowel[i] = i == 0 ? ans : Vowel[i - 1] + ans;
        }

        int m = queries.size();
        vector<int> result(m, 0);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            result[i] = countV(l, r, Vowel);
        }

        return result;
    }
};