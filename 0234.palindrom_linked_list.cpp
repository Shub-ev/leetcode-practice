/* 
 * Given the head of a singly linked list, return true if it is a
 * palindrome or false otherwise.
 */

#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * Using recursion.
 * TC: O(n)
 * SC: O(n)
*/
class Solution {
    std::vector<int> nodes;
    int idx = 0;
public:
    bool isPalindrome(ListNode* head) {
        // push elements into array
        if(head == nullptr) return true;
        nodes.push_back(head->val);
        bool res = isPalindrome(head->next);

        // at returning compare front of array with tail of linked list
        return (head->val == nodes[idx++]) && res;
    }
};

// There is more optimal alternative available on leetcode