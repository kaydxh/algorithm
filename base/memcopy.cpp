/*
 Memcopy和memmove函数在linux下看了一下两个函数的源码。

两个函数都在头文件string.h中定义，函数原型为：

void * __cdecl memcpy ( void * dst,const void * src,size_t count)；

void * __cdecl memmove ( void * dst,const void * src,size_t count)；
 */
#include <iostream>
using namespace std;

void *memcpy(void *dst, const void *src, size_t count) {
    void *ret = dst;

    while (count--) {  // 注意， memcpy函数没有处理dst和src区域是否重叠的问题

        *(char *)dst = *(char *)src;

        dst = (char *)dst + 1;

        src = (char *)src + 1;
    }

    return (ret);
}

void *memmove(void *dst, const void *src, size_t count) {
    void *ret = dst;

    if (dst <= src || (char *)dst >= ((char *)src + count)) {
        // 若dst和src区域没有重叠，则从起始处开始逐一拷贝

        while (count--)

        {
            *(char *)dst = *(char *)src;

            dst = (char *)dst + 1;

            src = (char *)src + 1;
        }

    } else {  // 若dst和src
              // 区域交叉，则从尾部开始向起始位置拷贝，这样可以避免数据冲突

        dst = (char *)dst + count - 1;

        src = (char *)src + count - 1;

        while (count--) {
            *(char *)dst = *(char *)src;

            dst = (char *)dst - 1;

            src = (char *)src - 1;
        }
    }

    return (ret);
}

int main() {
    char src[] = "hello word";
    char dst[sizeof(src)] = "0";
    memcpy(dst, src, sizeof(src));
    cout << "dst:" << dst << ",len:" << sizeof(dst) << endl;
}
