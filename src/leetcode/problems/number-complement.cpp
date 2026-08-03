#include "leetcode/problems/number-complement.h"

namespace leetcode {
namespace problem_476 {
namespace {

int findComplementImpl(int num) {
    // 计算 num 的有效位长度 n，掩码 = (1 << n) - 1
    int n = 0;
    int temp = num;
    while (temp > 0) {
        temp >>= 1;
        ++n;
    }
    // 用 unsigned long 确保移位与取反安全，避免符号相关 UB
    unsigned long allOnes = (1UL << n) - 1UL;
    return static_cast<int>(~static_cast<unsigned long>(num) & allOnes);
}

}  // namespace

NumberComplementSolution::NumberComplementSolution() {
    setMetaInfo({.id = 476,
                 .title = "Number Complement",
                 .url = "https://leetcode.com/problems/number-complement/"});
    registerStrategy(
        {.name = "BitMaskComplement",
         .expected = "Accepted",
         .time_complexity = "O(1)",
         .space_complexity = "O(1)",
         .tags = {"Bit Manipulation"}},
        findComplementImpl);
}

int NumberComplementSolution::findComplement(int num) {
    return getSolution()(num);
}

}  // namespace problem_476
}  // namespace leetcode
