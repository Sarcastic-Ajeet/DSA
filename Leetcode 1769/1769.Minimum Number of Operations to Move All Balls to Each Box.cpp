// Leetcode : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
/**********************Brute force approach*****************/
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int>result(n , 0);
        for(int i = 0; i < n ; i++){
            if(boxes[i] == '1'){
                for(int j = 0; j < n ; j++){
                    result[j] += abs(j-i);
                }
            }
        }
        return result;
    }
};

/**********************Second approach*****************/
// T.C = O(n)
// S.C = O(2n)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        if(n == 1) return {0};
        vector<int>left(n , 0) , right(n , 0);
        int count = boxes[n-1] == '1' ? 1 : 0;
        for(int i = n-2; i >= 0 ; i--){
            right[i] = right[i+1] + count;
            if(boxes[i] == '1') count++;
        }
        count = boxes[0] == '1' ? 1 : 0;
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] + count;
            if(boxes[i] == '1') count++;
        }

        // vector<int>result(n , 0);
        for(int i = 0; i < n ; i++){
            left[i] = left[i] + right[i];
        }

        return left;        
    }
};

