/*
 * Alice and Bob are playing a game. Initially, Alice has a string word = "a".
 * You are given a positive integer k.
 * Now Bob will ask Alice to perform the following operation forever:
 * 
 * Generate a new string by changing each character in word to its next character in the
 * English alphabet, and append it to the original word.
 * For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
 * Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.
 * 
 * Example 1:
 * Input: k = 5
 * Output: "b"
 * Explanation:
 * Initially, word = "a". We need to do the operation three times:
 * Generated string is "b", word becomes "ab".
 * Generated string is "bc", word becomes "abbc".
 * Generated string is "bccd", word becomes "abbcbccd".
 * 
 * Example 2:
 * Input: k = 10
 * Output: "c"
 * 
 * Constraints:
 * 1 <= k <= 500
 */

#include <iostream>

class Solution {
public:
    std::string str = "a";
    char kthCharacter(int k) {
        if(str.length() >= k) return str[k-1];

        std::string temp = str;
        for(int i = 0; i < str.length(); i++) {
            temp += (str[i] + 1);
        }
        str = temp;
        std::cout << str << "\n";
        return kthCharacter(k);
    }
};

// better approach is present on leetcode