//
// Created by kayxhding on 2020-06-10 23:07:09
//

/*
   Given an absolute path for a file (Unix-style), simplify it. Or in other
words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory.
Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and
there must be only a single slash / between two directory names. The last
directory name (if it exists) must not end with a trailing /. Also, the
canonical path must be the shortest string representing the absolute path.

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root
level is the highest level you can go. Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by
a single one. Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    /*
     * 思路与算法
    我们首先将给定的字符串 path 根据 / 分割成一个由若干字符串组成的列表，记为
    names。根据题目中规定的「规范路径的下述格式」，names
    中包含的字符串只能为以下几种：

    1. 空字符串。例如当出现多个连续的 /，就会分割出空字符串；

    2. 一个点 .；

    3. 两个点 ..；

    4. 只包含英文字母、数字或 _的目录名。

    对于「空字符串」以及「一个点」，我们实际上无需对它们进行处理，因为「空字符串」没有任何含义，而「一个点」表示当前目录本身，我们无需切换目录。

    对于「两个点」或者「目录名」，我们则可以用一个栈来维护路径中的每一个目录名。当我们遇到「两个点」时，需要将目录切换到上一级，因此只要栈不为空，我们就弹出栈顶的目录。当我们遇到「目录名」时，就把它放入栈。

    这样一来，我们只需要遍历names中的每个字符串并进行上述操作即可。在所有的操作完成后，我们将从栈底到栈顶的字符串用/
    进行连接，再在最前面加上 /  表示根目录，就可以得到简化后的规范路径。

    复杂度：
    时间复杂度：O(n)，其中 n 是字符串 path 的长度。
    空间复杂度：O(n)。我们需要 O(n) 的空间存储 names中的所有字符串
   */
    vector<string> splitPath(const string& s, char delim) {
        vector<string> result;
        string cur;
        for (char ch : s) {
            if (ch == delim) {
                result.push_back(std::move(cur));
                cur.clear();
            } else {
                cur += ch;
            }
        }
        result.push_back(std::move(cur));
        return result;
    }

    string simplifyPath(string path) {
        string result;
        vector<string> names = splitPath(path, '/');
        vector<string> stack;
        for (string& name : names) {
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (!name.empty() && name != ".") {
                stack.push_back(std::move(name));
            }
        }
        if (stack.empty()) {
            result = "/";
        } else {
            for (string& name : stack) {
                result += "/" + std::move(name);
            }
        }

        return result;
    }
    /*
     使用一前一后指针，前指针遍历到‘/’后停止，获取前后指针的内容name，
     如果name不为空或者不是"."， 就将name压入stack中
     如果name == ".."，就判断stack是否为空，不为空，就pop
     更新前后指针，left= right； ++right
     最后遍历stack，用“/”连接起来
     如果stack为空，就返回“/”
     复杂度：
     时间复杂度：O(n)
     空间复杂度：O(n)
    */

#if 0
    string simplifyPath(string path) {
        if (path.empty()) {
            return path;
        }

        string result;
        stack<string> path_stack;
        int left = 0;
        int right = 0;
        for (right = 0; right < path.length(); ++right) {
            if (path[right] == '/') {
                while (right > 0 && path[right - 1] == path[right] &&
                       path[right] == '/') {
                    ++left;
                    ++right;
                }
                if (right - left > 1) {
                    string name = path.substr(left + 1, right - left - 1);
                    if (name == ".") {
                        left = right;
                    } else if (name == "..") {
                        if (path_stack.size() > 0) {
                            path_stack.pop();
                        }
                        left = right;
                    } else {
                        path_stack.push(name);
                        left = right;
                    }
                }
            }
        }

        if (path.length() - 1 > left) {
            string name = path.substr(left + 1, path.length() - left - 1);
            if (name == ".") {
            } else if (name == "..") {
                if (path_stack.size() > 0) {
                    path_stack.pop();
                }
            } else {
                path_stack.push(name);
            }
        }

        while (path_stack.size() > 0) {
            result.insert(0, "/" + path_stack.top());
            path_stack.pop();
        }

        return result.size() > 0 ? result : "/";
    }
#endif
};

int main() {
    string path = "/a//b////c/d//././/..";
    Solution sol;
    auto result = sol.simplifyPath(path);
    cout << result << endl;
}
