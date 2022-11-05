#include <algorithm>
#include <iostream>
using namespace std;
/*
1.把待排序的元素按照大小在二叉树位置上排列，排序好的元素要满足：父节点的元素要大于等于其子节点；这个过程叫做堆化过程，如果根节点存放的是最大的数，则叫做大根。
2.根据这个特性（大根堆根最大，小根堆根最小），就可以把根节点拿出来，然后再堆化下，再把根节点拿出来...，循环到最后一个节点，就排序好了
3. 升序排序->大根堆
   降序排序->小根堆
4. 复杂度
   时间复杂度：O(nlogn) (建堆排序时间复杂度O(n))
   空间复杂度：O(1) 就地排序
 */

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void percolateDown(int *a, int len, int parent) {
    int child = 2 * parent + 1;
    while (child < len) {
        //左孩子小于右孩子，就child++，得到右孩子索引
        if ((child + 1) < len && a[child] < a[child + 1]) {
            child++;
        }

        // a[child]为左右孩子中最大者
        // 如果孩子的最大者大于父亲，那么就交换孩子和父亲
        if (a[child] > a[parent]) {
            ::swap(a[child], a[parent]);
            // 更新父亲索引，
            parent = child;
            //更新左孩子索引
            child = 2 * parent + 1;

        } else {
            //如果父亲大于孩子的节点，那么堆秩序性就满足，然后break
            break;
        }
    }
}

//最大堆
void buildHeap(int *a, int n) {
    //从n-2开始，父节点最大为n-2（n的节点，最大节点为n-1，最大父节点为n-2),
    // n-1最后一个节点必然是叶子节点，最后一个叶子节点无需主动判断，由它的父节点判断调整后，自然就跟随调整了
    for (int i = n - 2; i >= 0; --i) {
        percolateDown(a, n, i);
    }
}

void heapSort(int *a, int n) {
    //最大堆建完后，最大者在第0位，所以需要和将第0位与最后一位交换（最大者归位），然后在进行下滤，保持堆秩序性
    buildHeap(a, n);
    int end = n - 1;
    while (end > 0) {
        ::swap(a[0], a[end]);
        percolateDown(a, end, 0);
        --end;
    }
}

int main() {
    int a[] = {2, 1, 6, 3, 9, 7, 4, 8, 5};
    heapSort(a, sizeof(a) / sizeof(int));

    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
        cout << a[i] << " ";
    }

    cout << endl;
}

