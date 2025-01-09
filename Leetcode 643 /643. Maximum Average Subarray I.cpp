/**************************************************CPP**********************************************/
// T.C = O(n)
// S.C = O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k ;i++){
            sum += nums[i];
        }
        double result = sum / (k*1.0); 
        
        for(int i = k; i < nums.size() ; i++){
            sum += (-nums[i - k] + nums[i]);
            result = max(result ,sum / (k*1.0));
        }
        return result;
    }
};

/**************************************************JavaScript**********************************************/
// T.C = O(n)
// S.C = O(1)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(nums, k) {
    let sum = 0;
    for(let i = 0; i < k ; i++){
        sum += nums[i];
    }
    let result = sum/k

    for(let i = k ;i < nums.length ; i++){
        sum += (-nums[i - k] + nums[i]);
        result = Math.max(result, sum / k);
    }
    return result;
};
