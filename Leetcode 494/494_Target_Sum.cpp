// Leetcode : https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26 
/*************************** Brute Force Approach *******************************************/
class Solution {
public:
    int result = 0;
    void solve(int index , int sum , vector<int>&nums , int target){
        //base case
        if(index >= nums.size()){
            if(sum == target) result++;
            return ;
        }

        // + adding the current Number
        solve(index+1 , nums[index] + sum , nums , target);
        // - subtracting the current number
        solve(index+1 , -nums[index] + sum , nums , target);
 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(0 , 0, nums , target);
        return result;
    }
};



/*************************** Memoization Using Hash Map *******************************************/
int solve(int index , int sum , vector<int>&nums , int target , unordered_map<string ,int>&mp){
    if(index >= nums.size()){
        if(sum == target) return 1;
        return 0;
    }
    string ans = to_string(index) + "_" + to_string(sum);
    if(mp.count(ans)) return mp[ans];
    // +
    int leftAns = solve(index+1 , nums[index] + sum , nums , target , mp);
    // -
    int rightAns = solve(index+1 , -nums[index] + sum , nums , target , mp);
    mp[ans] = leftAns+rightAns;
    return mp[ans];
   
}
int findTargetSumWays(vector<int>& nums, int target) {
    
    unordered_map<string ,int>mp;
    return solve(0 , 0, nums , target mp);
    // return result;
}



/*************************** Memoization Using Map *******************************************/
// using vector and to avoid the negative index, we will use the add the total sum to cuurent some 
class Solution {
public:
    int S;
    int solve(int index , int sum , vector<int>&nums , int target, vector<vector<int>>&mp){
        if(index >= nums.size()){
            if(sum == target) return 1;
            return 0;
        }

        
        if(mp[index][sum + S] != -1) return mp[index][sum + S];
        // +
        int leftAns = solve(index+1 , nums[index] + sum , nums , target , mp);
        // -
        int rightAns = solve(index+1 , -nums[index] + sum , nums , target , mp);

        mp[index][sum + S] = leftAns + rightAns;
        return mp[index][sum + S];
       
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        S = accumulate(nums.begin() , nums.end() , 0);
        vector<vector<int>>mp(n + 1 , vector<int>(2*S + 1 , -1));
        return solve(0 , 0, nums , target, mp);
    }
};
