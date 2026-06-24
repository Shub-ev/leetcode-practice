/*
 * Problem Statement: 1422. Maximum Score After Splitting a String
 * Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty
 * substrings (i.e. left substring and right substring).
 * The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.
 * 
 * Example 1:
 * Input: s = "011101"
 * Output: 5 
 * Explanation: 
 * All possible ways of splitting s into two non-empty substrings are:
 * left = "0" and right = "11101", score = 1 + 4 = 5 
 * left = "01" and right = "1101", score = 1 + 3 = 4 
 * left = "011" and right = "101", score = 1 + 2 = 3 
 * left = "0111" and right = "01", score = 1 + 1 = 2 
 * left = "01110" and right = "1", score = 2 + 1 = 3
 * 
 * Example 2:
 * Input: s = "00111"
 * Output: 5
 * Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
 * 
 * Example 3:
 * Input: s = "1111"
 * Output: 3
 * Explanation: When left = "111" and right = "1", we get the maximum score = 3 + 0 = 3
 * 
 * Constraints:
 * 2 <= s.length <= 500
 * The string s consists of characters '0' and '1' only.
 */

#include <iostream>
using namespace std;

// My Solution:
// The idea is to count the number of 1's in the string and then iterate through the string,
// keeping track of the number of 0's in the left substring and the number of 1's in the right substring.
// We update the maximum score at each split point.
// This is a form of prefix sum.
//
// Time complexity: O(n) where n is the length of the input string s. We iterate through the string twice,
//                       once to count the number of 1's and once to calculate the maximum score.
// Space complexity: O(1) since we are using a constant amount of extra space.
class Solution {
public:
    int maxScore(string s) {
        int sum_1 = 0;
        int sum_0 = 0;
        int len = s.length() - 1;

        for(char c: s)
            if(c == '1') sum_1++;

        int res = 0;
        for(int i = 0; i < len; i++) {
            if (s[i] == '0'){
                res = max(res, (sum_1 + (++sum_0)));
            }
            else
                res = max(res, --sum_1 + sum_0); 
        }

        return res;
    }
};