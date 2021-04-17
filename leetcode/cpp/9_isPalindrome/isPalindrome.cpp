
#include <iostream>
using namespace std;

/*
1.
第一个想法是将数字转换为字符串，并检查字符串是否为回文。但是，这需要额外的非常量空间来创建问题描述中所不允许的字符串。
2.
第二个想法是将数字本身反转，然后将反转后的数字与原始数字进行比较，如果它们是相同的，那么这个数字就是回文。
但是，如果反转后的数字大于INT_MAX，我们将遇到整数溢出问题
3.
为了避免数字反转可能导致的溢出问题，为什么不考虑只反转数字的一半？毕竟，如果该数字是回文，其后半部分反转后应该与原始数字的前半部分相同

时间复杂度：
1. 对于每次迭代，我们会将输入除以10，因此时间复杂度为
O(log_{10}(n)) 10
2. 空间复杂度：O(1)
*/

class Solution {
   public:
    /*
// 如上所述，当 x < 0 时，x 不是回文数。
// 同样地，如果数字的最后一位是 0，为了使该数字为回文，
// 则其第一位数字也应该是 0
// 只有 0 满足这一属性
*/
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedValue = 0;
        while (x > reversedValue) {
            int n = x % 10;
            reversedValue = reversedValue * 10 + n;
            x /= 10;
            std::cout << reversedValue << std::endl;
        }

        // 当数字长度为奇数时，我们可以通过 reversed_value/10
        // 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x =
        // reversed_value = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == reversedValue || x == reversedValue / 10;
    }
};

int main() {
    Solution sol;
    auto result = sol.isPalindrome(123);
    std::cout << result << std::endl;
    return 0;
}
