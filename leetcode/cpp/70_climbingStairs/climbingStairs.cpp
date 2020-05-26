//
// Created by kayxhding on 2020-05-26 22:57:36
//

/*
   You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  /*
  1. 思路：
  （1）
  如果整个台阶只有1级，则显然只有一种跳法，如果台阶有2级，则有2种跳法：一种是分两次跳，每次跳1级；另一种是一次跳2级。
  （2）推广到一般情况，把n级台阶的跳法看成是n的函数，即为f(n)。当n>2时，第一次跳1级还是2级，决定了后面剩下的台阶的跳法数目的不同：
     * 如果第一次只跳1级，则后面剩下的n-1级台阶的跳法数目为f(n-1)
     * 如果第一次跳2级，则后面剩下的n-2级台阶的跳法数目为f(n-2)
  因此：当n>2时，n级台阶的不同跳法的总数f(n)=f(n-1) + f(n-2)

  (3) 利用之前计算的结果一步步递推。初始化时，令dp[0] = dp[1] = 1,然后递推dp[n]
  = dp[n - 1] + dp[n - 2]即可 (4) 优化空间复杂度，使用int dp[3] = {1,1,1}; dp[2]
  = dp[1] +  dp[0]; dp[0] = dp[1]; dp[1] = dp[2]; 迭代更新，空间复杂度为O(1)


  复杂度：
  时间复杂度O(n)
  空间复杂度O(1)
*/
  int climbStairs(int n) {
    vector<int> dp = {1, 1, 1};
    for (int i = 2; i <= n; ++i) {
      dp[2] = dp[1] + dp[0];
      dp[0] = dp[1];
      dp[1] = dp[2];
    }

    return dp[2];
  }
};

int main() {
  Solution sol;
  auto result = sol.climbStairs(10);
  cout << result << endl;
}
