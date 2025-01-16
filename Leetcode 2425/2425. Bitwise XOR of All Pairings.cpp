// T.C = O(n or m)
// S.C = O(1)

/*********************************** CPP *************************************/
class Solution {
public:
    int xorCal(vector<int>&nums){
        int result = 0 , n = nums.size();
        for(int i = 0; i < n ; i++){
            result ^= nums[i];
        }
        return result;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0 , m = nums1.size() , n = nums2.size();

        if(n & 1){
            result ^= xorCal(nums1);
        }
        if(m & 1){
            result ^= xorCal(nums2);
        }

        return result;       
    }

};


/*********************************** JavaScript *************************************/

//////////////////////////////////// using for loop
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
function xorCal(nums){
    let n = nums.length
    let result = 0
    for(let  i = 0; i < n ; i++) result ^= nums[i]

    return result;
}
var xorAllNums = function(nums1, nums2) {
    let result = 0
    let m = nums1.length
    let n = nums2.length

    if(m & 1){
        result ^= xorCal(nums2)
    }
    if(n & 1){
        result ^= xorCal(nums1)
    }
    return result;
    
};

////////////////////////////////////// Using ForEach loop
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */

var xorAllNums = function(nums1, nums2) {
    let result = 0
    let m = nums1.length
    let n = nums2.length

    if(m & 1){
        nums2.forEach((num) => result ^= num)
    }
    if(n & 1){
        nums1.forEach((num) => result ^= num)
    }
    return result;
    
};


