#include <algorithm>
#include <iostream>
using namespace std;

/*
 * 思路：
（1）：在S中选取主元pivot
（2）：使用哨兵i，j分别从S的两端探测，当a[i]>pivot时，停止，当a[j]<pivot时停止，
    若i < j (i和j没有相遇过)，则交换a[i]和a[j]。
    直到i和j相遇过，跳出循环，此时a[i]≥pivot。
（3）：让主元归位
（4）：将数组分成2半，递归上述1,2,3过程
    时间复杂度O(nlogn), 最坏情况是O(n^2), 数组已经排序过的，或倒叙排序过的
    空间复杂度O(logn), 因为递归实现。
 */

int median3(int *a, int left, int right) {
    if (NULL == a) {
        return 0;
    }

    int center = (left + right) / 2;

    if (a[left] > a[center]) {
        swap(a[left], a[center]);
    }

    if (a[left] > a[right]) {
        swap(a[left], a[right]);
    }

    if (a[center] > a[right]) {
        swap(a[center], a[right]);
    }

    // a[left] <= a[center] <= a[right]
    // 这里将主元存储在right-1的位置上，将为i提供一个警戒位置, 方便主元归为
    swap(a[center], a[right - 1]);
    return a[right - 1];
}

void quickSort(int *a, int left, int right) {
    if (NULL == a) {
        return;
    }

    if (left < right) {
        int pivot = median3(a, left, right);

        int i = left;
        int j = right - 1;

        for (;;) {  //这个循环目的就是遍完数组，让i和j相遇
            while (a[++i] < pivot) {
            }
            while (a[--j] > pivot) {
            }

            if (i < j) {
                swap(a[i], a[j]);  // 当哨兵i和j没有相遇时，交换
            } else {
                break;  //这时i和j已经相遇过了，a[i]≥pivot的
            }
        }

        //主元存储在right-1位置，进行主元归位到位置i
        swap(a[i], a[right - 1]);  // a[i]≥pivot，把主元归位

        quickSort(a, left, i - 1);   //递归处理左子数组
        quickSort(a, i + 1, right);  //递归处理右子数组
    }
}

int main() {
    int a[] = {2, 1, 6, 3, 9, 7, 4, 8, 5};
    int left = 0;
    int right = sizeof(a) / sizeof(int) - 1;
    quickSort(a, 0, right);
    for (int i = 0; i <= right; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
