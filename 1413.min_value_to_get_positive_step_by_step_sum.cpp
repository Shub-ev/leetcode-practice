/*
 * Problem Statement: 1413. Minimum Value to Get Positive Step by Step Sum
 * Given an array of integers nums, you start with an initial positive value startValue.
 * In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
 * Return the minimum positive value of startValue such that the step by step sum is never less than 1.
 *
 * Example 1:
 * Input: nums = [-3,2,-3,4,2]
 * Output: 5
 * Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
 * step by step sum
 * startValue = 4 | startValue = 5 | nums
 *   (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
 *   (1 +2 ) = 3  | (2 +2 ) = 4    |   2
 *   (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
 *   (0 +4 ) = 4  | (1 +4 ) = 5    |   4
 *   (4 +2 ) = 6  | (5 +2 ) = 7    |   2
 * 
 * Example 2:
 * Input: nums = [1,2]
 * Output: 1
 * Explanation: Minimum start value should be positive. 
 * 
 * Example 3:
 * Input: nums = [1,-2,-3]
 * Output: 5
 * 
 * Constraints:
 * 1 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 */

#include <iostream>
#include <vector>
using namespace std;

// My solution:
// The idea is to calculate the prefix sums and find the minimum value among them.
// The minimum start value will be such that even the lowest prefix sum becomes at least 1.
// 
// Time complexity: O(n) where n is the length of the input array nums. We iterate through the array once to calculate the prefix sums and find the minimum value.
// Space complexity: O(n) for storing the prefix sums.
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        int min = nums[0];

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
            if(min > prefix[i]) min = prefix[i];
        }

        if(min > 0) return 1;
        else return abs(min) + 1;
    }
};


// Better solution:
// The idea is to calculate the prefix sums and find the minimum value among them.
// The minimum start value will be such that even the lowest prefix sum becomes at least 1
//
// Time complexity: O(n) where n is the length of the input array nums. We iterate through the array once to calculate the prefix sums and find the minimum value.
// Space complexity: O(1) as we are not using any extra space to store the
class Solution {
public:
    int minStartValue(vector<int>& A) {
        int ans = 0, sum = 0;
        for(auto el : A)
            sum += el, ans = min(ans, sum);
        return -ans+1;
    }
};