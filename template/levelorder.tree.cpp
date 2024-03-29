#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
层次遍历：
在 while 循环中加一个 for
循环，循环次数是循环前的队列中的元素个数即可，使得每次的 while
循环出队的元素都是同一层的元素。
复杂度：
时间复杂度：每个点进队出队各一次，故渐进时间复杂度为 O(n)。
空间复杂度：队列中元素的个数不超过 n 个，故渐进空间复杂度为 O(n)
*/
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> nodes_queue;
    TreeNode *node = root;
    if (node != nullptr) {
        nodes_queue.push(node);
    }

    while (!nodes_queue.empty()) {
        vector<int> level_elements;
        int level_nums = nodes_queue.size();
        for (int i = 0; i < level_nums; ++i) {
            node = nodes_queue.front();
            if (node != nullptr) {
                level_elements.push_back(node->val);
            }
            nodes_queue.pop();

            if (node->left) {
                nodes_queue.push(node->left);
            }
            if (node->right) {
                nodes_queue.push(node->right);
            }
        }

        if (level_elements.size() > 0) {
            result.push_back(level_elements);
        }
    }

    return result;
}
