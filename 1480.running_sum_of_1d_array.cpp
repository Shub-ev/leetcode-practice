/*
 * Problem Statement: 1480. Running Sum of 1d Array
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [1,3,6,10]
 * Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
 * 
 * Example 2:
 * Input: nums = [1,1,1,1,1]
 * Output: [1,2,3,4,5]
 * Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
 * 
 * Example 3:
 * Input: nums = [3,1,2,10,1]
 * Output: [3,4,6,16,17]
 * 
 * Constraints:
 * 1 <= nums.length <= 1000
 * -10^6 <= nums[i] <= 10^6
 */

#include <iostream>
#include <vector>
using namespace std;

// My solution:
// We iterate through the array and maintain a running sum.
// For each element, we add it to the running sum and store the result in the output array.
// 
// Time complexity: O(n) where n is the length of the input array nums. We iterate through the array once to calculate the running sum.
// Space complexity: O(n) for storing the output array.
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int prev = 0;
        for(int num: nums) {
            res.push_back(num + prev);
            prev = res.back();
        }

        return res;
    }
};


// My better solution:
// We iterate through the array and maintain a running sum.
// For each element, we add it to the running sum and store the result in the same array to save space.
// Time complexity: O(n) where n is the length of the input array nums. We iterate through the array once to calculate the running sum.
// Space complexity: O(1) as we are not using any extra space to store the output array.
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            nums[i] = nums[i-1] + nums[i];
        }

        return nums;
    }
};