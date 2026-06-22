/*
 * Given a non-empty array of integers nums, every element appears twice except for one.
 * Find that single one.You must implement a solution with a linear runtime complexity
 * and use only constant extra space.
 * 
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * 
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * 
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 * 
 * Constraints:
 * 1 <= nums.length <= 3 * 104
 * -3 * 104 <= nums[i] <= 3 * 104
 * Each element in the array appears twice except for one element which appears only once.
*/

#include <vector>

/*
* Idea:
* XOR all elements in the array.
*
* XOR properties:
* 1. a ^ a = 0      -> same numbers cancel each other
* 2. a ^ 0 = a      -> XOR with 0 keeps the number unchanged
* 3. XOR is commutative and associative
*    -> order does not matter
*
* Since every element appears twice except one:
*
* Example:
* [4, 1, 2, 1, 2]
*
* 4 ^ 1 ^ 2 ^ 1 ^ 2
* = 4 ^ (1 ^ 1) ^ (2 ^ 2)
* = 4 ^ 0 ^ 0
* = 4
*
* TC: O(n)  -> traverse array once
* SC: O(1)  -> constant extra space
*/
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int track = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            track ^= nums[i];
        }
        return track;
    }
};