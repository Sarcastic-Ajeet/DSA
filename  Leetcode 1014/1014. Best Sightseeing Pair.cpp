// Leetcode : https://leetcode.com/problems/best-sightseeing-pair/description/?envType=daily-question&envId=2024-12-27

/************************************ Approach -1 Brute Froce Approach *************************************/
// T.C = O(n^2)
// S.C = O(n)

// make all pair and check the make maximum answer value

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = INT_MIN , n = values.size();
        for(int i = 0; i < n ; i++){
            for(int j = i+1; j < n ; j++){
                result = max(result , values[i] + values[j] + i - j);
            }
        }

        return result;
        
    }
};

// this will lead to Time limit exceed 

/************************************ Approach -2 *************************************/
// T.C = O(n)
// S.C = O(n)

// result[i] = values[i] + values[j] + i - j
// result[i] = (values[i] + i) + (values[j]  - j)
// we'll previously calculate the (values[i] + i) and store the value
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = INT_MIN , n = values.size();
        vector<int>max_i(n , 0);
        max_i[0] = values[0] + 0;
        // calculating (values[i] + i)
        for(int i = 1; i < n ; i++){
            max_i[i] = max(max_i[i-1] , values[i] + i);
        }
        // result[i] = (values[i] + i) + (values[j]  - j)
        for(int i = 1; i < n ; i++){
            result = max(result , max_i[i-1] + values[i] - i);  
        }

        return result;
        
    }

};

