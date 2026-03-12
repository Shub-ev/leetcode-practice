/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45
*/

// 1. Naive Recursive solution
// TC: O(2^n)
// SC: O(1)
// Hence, raise TLE (Time Limit Exceeded)
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// 2. Dynamic Programmin with Memorization (Top-Down Approach) Solution
// TC: O(N)
// SC: O(N) + O(N) (second one because of recursion stack)
// Hence this can also generate TLE
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        vector<int> arr(n+1, -1);
        recurr(n, arr);
        return arr[n];
    }

    int recurr(int n, vector<int> &arr) {
        if(n <= 2) {
            arr[n] = n;
            return n;
        }

        if(arr[n] != -1) {
            return arr[n];
        } else {
            arr[n] = recurr(n-1, arr) + recurr(n-2, arr);
            return arr[n];
        }
    }
};

// 3. Dynamic Programmin with Tabulation (Bottom-up Approach) Solution
// Here, we are not using recursion hence space optimal
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> arr(n+1, -1);
        arr[1] = 1;
        arr[2] = 2;
        for(int state = 3; state <= n; state++) {
            arr[state] = arr[state-1] + arr[state-2];
        }
        return arr[n];
    }
};

// 4. Dynamic Programmin with Tabulation Optimal
// In above program we are using array to store all solved states but
// in tabulation we are using only previous 2 states and we dont need all.
// Hence, we can use only 2 variables for memorization
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev1 = 1;
        int prev2 = 2;
        int ans = 0;
        for(int state = 3; state <= n; state++) {
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};
