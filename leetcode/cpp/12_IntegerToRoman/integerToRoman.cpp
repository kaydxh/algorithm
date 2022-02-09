/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
and M. Symbol       Value I             1 V             5 X             10 L 50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    /*
贪心算法
思想：
每一步都使用当前较大的罗马数字作为加法因子，最后得到罗马数字表示就是长度最少的
1. 将罗马字符和特殊的字符分别用2个数组保存，且按照从大到小的顺序存放
2. 遍历数字数组，若当前数字num >=
数组的当前数字nums[i]，就在对应romans数组的对应index，得到对应的罗马字符，之后更新数字num（num
-= nums[i]） （比如数字6， 在遍历是会在nums数组中的5满足 6 >= 5
条件，于是在romans数组中找到罗马字符V，之后num更新为1，再重复操作，直至循环结束）

复杂度：
1. 时间复杂度O(1),
虽然看起来是两层循环，但是外层循环的次数最多12，内层循环的此时其实也是有限次的，综合一下，时间复杂度是
O(1)
2.
空间复杂度：O(1)，这里使用了两个辅助数字，空间都为13，还有常数个变量，故空间复杂度是
O(1)
*/
    string intToRoman(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50,
                            40,   10,  9,   5,   4,   1};
        vector<string> romans = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                 "XL", "X",  "IX", "V",  "IV", "I"};

        string result;
        for (auto i = 0; i < nums.size(); i++) {
            if (num > nums[i]) {
                result += romans[i];
                num -= nums[i];
            }
        }

        return result;
    }
};

int main() {
    int num = 3009;
    Solution sol;
    auto result = sol.intToRoman(num);
    std::cout << result << std::endl;
    return 0;
}
