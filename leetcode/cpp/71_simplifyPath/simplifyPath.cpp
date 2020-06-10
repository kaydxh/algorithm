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
};

int main() {
  string path = "/a//b////c/d//././/..";
  Solution sol;
  auto result = sol.simplifyPath(path);
  cout << result << endl;
}
