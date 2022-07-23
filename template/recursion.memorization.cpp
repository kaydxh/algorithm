/*
 * 递归-memorization 缓存，避免重复计算
 * 1 递归终止条件
 * 2 递归关系 =》 大问题转化为小问题
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int memorizationHelp(std::map<int, int> &cache, int n) {
    auto iter = cache.find(n);
    if (iter != cache.end()) {
        return iter->second;
    }

    int result = 0;
    /*
    //1. base case
       if (n < 2) {
        result  = 2;
      }

    //2. recursion relation
     result =  memorizationHelp(cache, n - 1) + memorizationHelp(cache, n - 2);
    */
    // 3. update cache
    cache[n] = result;
    return result;
}

int memorization(int n) {
    std::map<int, int> cache;
    return memorizationHelp(cache, n);
}

int main() {
    int n = 4;
    std::cout << memorization(4) << std::endl;
}
