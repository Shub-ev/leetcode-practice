/*
You are given an integer array cost where cost[i] is the cost of ith step on a
staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/


// 1. Naive Recursion
// Disadvantage:
// 1. Recursion stack increases space and time complexity indirectly
// TC: O(N)
// SC: O(N) due to recursion stack
// 2. solve overlapping sub-problems.
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return recur(cost, n);
    }
    int recur(vector<int> &cost, int n) {
        if(n < 2) { return 0; }
        return min((cost[n-1] + recur(cost, n-1)), (cost[n-2] + recur(cost, n-2)));
    }
};


// 2. Dynamic Programmin with Memorization (Top-Down)
// TC: O(N)
// SC: O(N) + O(N)          // Array for memorization + recursive stack
// 
// Advantage:
// 1. Avoid solving overlapping sub_problems.
// Disadvantage:
// 1. Recursion Stack increases time and space complexity
class Solution {
public:
    // Memorization (top-down)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> res(n+1, -1);
        recur(cost, res, n);
        return res[n];
    }
    int recur(vector<int> &cost, vector<int> &res, int n) {
        if(n < 2) { 
            dp[n] = 0;
            return 0; 
        }

        if(res[n] != -1) {
            return res[n];
        } else {
            res[n] = min((cost[n-1] + recur(cost, res, n-1)), (cost[n-2] + recur(cost, res, n-2)));
            return res[n];
        }
    }
};


// 3. Dynamic Programmin with Tabulation (Bottom-Up)
// Here we have avoided array as we are refering only n-1 and n-2 states for
// transition to nth state, we are using 2 variable.
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n < 2) return 0;
        int prev1 = 0;
        int prev2 = 0;
        int ans = 0;
        for(int state = 2; state <= n; state++) {
            int step1 = (cost[state-1] + prev1);
            int step2 = (cost[state-2] + prev2);
            ans = min(step1, step2);
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};
