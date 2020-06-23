//
// Created by kayxhding on 2020-06-23 09:04:54
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    for (int i = 1; i <= 3 && i < s.length() - 2; ++i) {
      for (int j = i + 1; j <= i + 3 && j < s.length() - 1; ++j) {
        for (int k = j + 1; k <= j + 3 && k < s.length(); ++k) {
          string s1 = s.substr(0, i);
          string s2 = s.substr(i, j - i);
          string s3 = s.substr(j, k - j);
          string s4 = s.substr(k, s.length());

          cout << "s1: " << s1 << ", s2: " << s2 << ", s3: " << s3
               << ", s4: " << s4 << endl;

          if (valid(s1) && valid(s2) && valid(s3) && valid(s4)) {
            result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
          }
        }
      }
    }

    return result;
  }

  bool valid(string s) {
    int a = atoi(s.c_str());  // stoi(s);
    if (s.length() == 0 || a < 0 || a > 255 ||
        (s.length() > 1 && s[0] == '0')) {
      return false;
    }

    return true;
  }
};

int main() {
  string s = "25525511135";
  Solution sol;
  auto result = sol.restoreIpAddresses(s);
  for (auto i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
}
