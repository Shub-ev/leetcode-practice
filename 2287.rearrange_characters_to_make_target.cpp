/*
 * 2287. Rearrange Characters to Make Target
 * You are given two 0-indexed strings s and target. You can take some letters from s and rearrange them to form new strings.
 * Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.
 *
 * Example 1:
 * Input: s = "ilovecodingonleetcode", target = "code"
 * Output: 2
 * Explanation:
 * For the first copy of "code", take the letters at indices 4, 5, 6, and 7.
 * For the second copy of "code", take the letters at indices 17, 18, 19, and 20.
 * The strings that are formed are "ecod" and "code" which can both be rearranged into "code".
 * We can make at most two copies of "code", so we return 2.
 * 
 * Example 2:
 * Input: s = "abcba", target = "abc"
 * Output: 1
 * Explanation:
 * We can make one copy of "abc" by taking the letters at indices 0, 1, and 2.
 * We can make at most one copy of "abc", so we return 1.
 * Note that while there is an extra 'a' and 'b' at indices 3 and 4, we cannot reuse the letter 'c' at index 2, so we cannot make a second copy of "abc".
 * 
 * Example 3:
 * Input: s = "abbaccaddaeea", target = "aaaaa"
 * Output: 1
 * Explanation:
 * We can make one copy of "aaaaa" by taking the letters at indices 0, 3, 6, 9, and 12.
 * We can make at most one copy of "aaaaa", so we return 1.
 * 
 * Constraints:
 * 1 <= s.length <= 100
 * 1 <= target.length <= 10
 * s and target consist of lowercase English letters.
 */

#include <map>
#include <climits>
using namespace std;

// My Solution:
// Time: O(n + m)   -> We need to count the frequency of characters in both s and target, which takes O(n) and O(m) time respectively.
// Space: O(n + m)  -> The space complexity is O(n + m) because we are storing the frequency counts in maps for both strings.
// We can use two maps to count the frequency of characters in s and target.
// Then, we can iterate through the characters in s and check how many times we can form target using the characters in s.
// The answer will be the minimum of the ratios of the counts in s to the counts in target for each character.
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> t_ins;
        for(char ch: target) {
            t_ins[ch]++;
        }

        map<char, int> s_ins;
        for(char ch: s) {
            if(!t_ins.count(ch)) continue;
            s_ins[ch]++;
        }

        if(s_ins.size() < t_ins.size()) return 0;

        int ans = INT_MAX;
        for (auto& pair: s_ins) {
            pair.second /= t_ins[pair.first];
            if(ans > pair.second) ans = pair.second;
        }

        return s_ins.empty() ? 0 : ans;
    }
};

// Optimized Solution:
// Time: O(n + m)   -> We still need to count the frequency of characters in both s and target, which takes O(n) and O(m) time respectively.
// Space: O(1)      -> We can optimize the space complexity by using an array of size 26 to count the frequency of characters instead of using maps.
// 
// We can optimize the space complexity by using an array of size 26 to count the frequency of characters instead of using maps. 
// This is because we are only dealing with lowercase English letters, which are limited to 26 characters.
// This way, we can reduce the space complexity to O(1) since the size of the array is constant.
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int t_ins[26] = {0};
        for(char ch: target) {
            t_ins[ch - 'a']++;
        }

        int s_ins[26] = {0};
        for(char ch: s) {
            if(t_ins[ch - 'a'] == 0) continue;
            s_ins[ch - 'a']++;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if(t_ins[i] == 0) continue;
            int ratio = s_ins[i] / t_ins[i];
            if(ans > ratio) ans = ratio;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};