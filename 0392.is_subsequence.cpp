// My First approach was to create an array of the same length as s and store the positions of the characters in t.
// Then I checked if the positions are in increasing order.
// This approach works but it is not efficient.

// The time complexity is O(n) where n is the length of t.
// The space complexity is O(m) where m is the length of s.

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="") return true;
        if(s == "" && t == "") return true;
        if(t == "") return false;

        int mainArrIdx = 0;
        int compArrIdx = 0;
        vector<int> pos(s.length(), -1);

        for (compArrIdx; compArrIdx < t.length();) {
            if(s[mainArrIdx] == t[compArrIdx]) {
                pos[mainArrIdx] = compArrIdx;
                mainArrIdx++;
                compArrIdx++;
            }
            else {
                compArrIdx++;
            }
        }

        if(mainArrIdx != pos.size()) return false;

        for(int i = 0; i < pos.size() - 1; i++) {
            if(pos[i] > pos[i+1]) return false;
        }

        return true;
    }
};

// The second approach is to use two pointers to traverse both strings.
// The time complexity is O(n) where n is the length of t.
// The space complexity is O(1).
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        for(i; i < t.length();) {
            if(s[j] == t[i]){
                j++;
                i++;
            } else
                i++;
        }

        return j == s.length();
    }
};