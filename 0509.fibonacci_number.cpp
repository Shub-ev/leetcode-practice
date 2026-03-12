/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
Fibonacci sequence, such that each number is the sum of the two preceding
ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
*/


// 1. Iteratice Solutions
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int fib(int n) {
        if(n == 1) return 1;
        if(n == 0) return 0;

        int first = 0, second = 1;
        for(int i = 1; i < n; i++) {
            int sum = first + second;
            first = second;
            second = sum;
        }
        return second;
    }
};


// 2. Recursive Solution
// disadvantage here is we are solving repetative sub-problems
// ex. fib(2) will be solved multiple times which increases TC.
// TC: O(2^N)
// SC: O(1)
class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        return fib(n-1) + fib(n-2);
    }
};


// 3. Dynamic programming with Memorization (Top-Down Approach) Solution
// In Top down approach we start from Main-Problem and we move to the smallest
// sub-problem.
// disadvantage here is we are using recursion hence function stack comes
// into picture so we are using arr for memorization and function stack.
// TC: O(N)
// SC: O(N)         // due to array we are using for memorization
class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        // Here using this vector array we are memorizing the solutions
        // to avoid overlapping sub_solutions.
        vector<int> arr(n+1, -1);
        recurr(n, arr);
        return arr[n];
    }

    int recurr (int n, vector<int> &arr) {
        if(n < 2) {
            arr[n] = n;
            return n;
        }

        // Here we are checking if we should do the recursive call for current
        // state of DP or not.
        if(arr[n] != -1) {
            return arr[n];
        } else {
            arr[n] = recurr(n-1, arr) + recurr(n-2, arr);
            return arr[n];
        }
    }
};

// 4. Dynamic Programming with Tabulation Solution (Bottom-Up approach)
// Iterative solution hence no function call stack.
// TC: O(N)
// SC: O(N)         // as we are using array for memorization
class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;

        vector<int> arr(n+1, -1);
        arr[0] = 0;
        arr[1] = 1;
        for(int state = 2; state <= n; state++) {
            arr[state] = arr[state-1] + arr[state-2];
        }
        return arr[n];
    }
};


// 5. In above solution we are using only n-1 and n-2 element to get the current state.
// Hence we dont need to memorize the complete array. We can replace whole array
// with prev1 and prev2.
// So this final solution for this problem with:
// Dynamic Programming with Tabulation. is same as Solution (1).
