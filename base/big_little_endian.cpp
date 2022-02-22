/*
 大端模式: 先存放最高有效字节，表现为最高有效字节存储在低地址
小端模式: 先存放最低有效字节，表现为最低有效字节存储在低地址
*/

#include <iostream>
using namespace std;

bool bigEndian1() {
    int x = 1;
    char *y = (char *)&x;
    if (*y) {
        return false;
    }

    return true;
}

union UN {
    int x;
    char y;
};
bool bigEndian2() {
    union UN un;
    un.x = 1;
    if (un.y) {
        return false;
    }

    return true;
}

int main() {
    bool bigedian = bigEndian2();
    if (bigedian) {
        cout << "bigedian" << endl;
    } else {
        cout << "littledian" << endl;
    }
}
