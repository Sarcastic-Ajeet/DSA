//leetcode : https://leetcode.com/problems/number-of-ways-to-split-array/description/

// T.C = O(n)
// S.C = O(1)

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            total_sum += nums[i]; 
        }

        long long curr = 0;
        int result = 0;
        for(int i = 0; i < n-1; i++){
            curr += nums[i];
            total_sum -= nums[i];
            if(curr >= total_sum) result++;
        } 
        return result;
        
    }
};