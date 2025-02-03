#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        // 检查是否需要填充缓存
        while (cached <= i) {
            if (cached == 0) {
                cache[cached] = 0;
            } else if (cached == 1) {
                cache[cached] = 1;
            } else {
                cache[cached] = cache[cached - 1] + cache[cached - 2];
            }
            ++cached;
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    fib.cached = 0;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
