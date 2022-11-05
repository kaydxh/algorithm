#include <ios>
#include <iostream>
using namespace std;

/*
 * 归并排序
思路：分解、解决（简单方法）、合并
（1）把一个数组分成两个数组，然后再把这两个数组各自分成两个数组
（2）重复1过程，直到子数组只有1个元素
（3）比较子数组的元素（两个元素比较即可），并合并到另外一个临时数组上
（4）将临时数组的元素copy到原数组中
 时间复杂度O(nlogn)。
 空间复杂度O(n)。
*/

void merge(int* a, int* b, int lBegin, int rBegin, int rEnd) {
    if (a == nullptr || b == nullptr) {
        return;
    }

    int lEnd = rBegin - 1;
    int tBegin = lBegin;
    int n = rEnd - lBegin + 1;
    int tmpLBegin = lBegin;

    while (lBegin <= lEnd && rBegin <= rEnd) {
        if (a[lBegin] > a[rBegin]) {
            b[tBegin++] = a[rBegin++];
        } else {
            b[tBegin++] = a[lBegin++];
        }
    }

    while (lBegin <= lEnd) {
        b[tBegin++] = a[lBegin++];
    }
    while (rBegin <= rEnd) {
        b[tBegin++] = a[rBegin++];
    }

    /*
    for (int i = 0; i < n; ++i, rEnd--) {
        a[rEnd] = b[rEnd];
    }
    */
    for (int i = tmpLBegin; i < tBegin; ++i) {
        a[i] = b[i];
    }
}

void mergeSort(int* a, int* b, int left, int right) {
    if (a == nullptr || b == nullptr) {
        return;
    }

    //注意这里是if不是while, 因为内部递归了
    if (left < right) {
        int center = left + (right - left) / 2;
        mergeSort(a, b, left, center);
        mergeSort(a, b, center + 1, right);
        merge(a, b, left, center + 1, right);
    }
}

int main() {
    int a[] = {2, 1, 6, 3, 9, 7, 4, 8, 5};
    int b[sizeof(a) / sizeof(int)] = {0};

    int left = 0;
    int right = sizeof(a) / sizeof(int) - 1;
    mergeSort(a, b, left, right);

    for (int i = 0; i <= right; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
