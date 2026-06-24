/*
 * Problem Statement: 303. Range Sum Query - Immutable
 * Given an integer array nums, handle multiple queries of the following type:
 * Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
 * 
 * Implement the NumArray class:
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 * 
 * Example 1:
 * Input
 * ["NumArray", "sumRange", "sumRange", "sumRange"]
 * [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * Output
 * [null, 1, -1, -3]
 * Explanation
 * NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
 * numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
 * numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
 * numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 * 
 * Constraints: 
 * 1 <= nums.length <= 104
 * -105 <= nums[i] <= 105
 * 0 <= left <= right < nums.length
 * At most 104 calls will be made to sumRange.
 */

#include <iostream>
#include <vector>
using namespace std;

// My solution:
// We use a prefix sum array to store the cumulative sums of the elements in the input array.
// This allows us to calculate the sum of any subarray in constant time with prefix[right] - prefix[left-1].
//
// Time complexity: O(n) for the constructor to build the prefix sum array, and O(1) for each sumRange query.
// Space complexity: O(n) for storing the prefix sum array.
class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            prefix.push_back(prefix[i-1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return prefix[right];
        else if (right == 0)
            return 0;
        else
            return prefix[right] - prefix[left-1];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */