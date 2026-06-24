/*
 * Problem statement: 724. Find Pivot Index
 * Given an array of integers nums, calculate the pivot index of this array.
 * The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all
 * the numbers strictly to the index's right.
 * If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
 * This also applies to the right edge of the array.
 * 
 * Return the leftmost pivot index. If no such index exists, return -1.
 * 
 * Example 1:
 * Input: nums = [1,7,3,6,5,6]
 * Output: 3
 * Explanation:
 * The pivot index is 3.
 * Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
 * Right sum = nums[4] + nums[5] = 5 + 6 = 11
 * 
 * Example 2:
 * Input: nums = [1,2,3]
 * Output: -1
 * Explanation:
 * There is no index that satisfies the conditions in the problem statement.
 * 
 * Example 3:
 * Input: nums = [2,1,-1]
 * Output: 0
 * Explanation:
 * The pivot index is 0.
 * Left sum = 0 (no elements to the left of index 0)
 * Right sum = nums[1] + nums[2] = 1 + -1 = 0
 * 
 * Constraints:
 * 1 <= nums.length <= 104
 * -1000 <= nums[i] <= 1000
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// My solution:
// This solution uses a prefix sum array to efficiently calculate the sum of elements to the left and right of each index.
// It first calculates the prefix sums, then iterates through the array to find the pivot index where the left and right sums are equal.
// 
// Time: O(n)   -> We need to calculate the prefix sum array, which takes O(n) time, and then iterate through the array to find the pivot index,
//                 which also takes O(n) time.
// Space: O(n)  -> We use an additional array to store the prefix sums,
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // calculate prefix sum array
        int n = nums.size();
        vector<int> prefix(n, -1);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        // iterate prefix sum to find prefix sum of range (left_sum PIVOT right_sum)
        if((prefix[n-1] - prefix[0]) == 0) return 0;

        for(int pivot = 1; pivot < n-1; pivot++) {
            int left_sum = prefix[pivot - 1];
            int right_sum = prefix[n-1] - prefix[pivot];

            if(left_sum == right_sum) return pivot;
        }

        if(prefix[n-2] == 0) return n-1;

        return -1;
    }
};


// Better Solution:
// This solution uses two variables to keep track of the left and right sums while iterating through the array.
// It calculates the right sum by taking the total sum of the array and subtracting the current element and the left sum.
// If the left and right sums are equal, it returns the current index as the pivot index.
// Time Complexity : O(n)
// Space Complexity : O(1)

// *** This solution may not look like prefix sum, but it is a prefix sum solution because we are not
//     calculating "prefix sum array", but only storing the current prefix sum ***
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Initialize rightSum to store the sum of all the numbers strictly to the index's right...
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        // Initialize leftSum to store the sum of all the numbers strictly to the index's left...
        int leftSum = 0;
        // Traverse all elements through the loop...
        for (int idx = 0; idx < nums.size(); idx++) {
            // subtract current elements with from rightSum...
            rightSum -= nums[idx];
            // If the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right...
            if (leftSum == rightSum)
                return idx;     // Return the pivot index...
            // add current elements with leftSum...
            leftSum += nums[idx];
        }
        return -1;      // If there is no index that satisfies the conditions in the problem statement...
    }
};