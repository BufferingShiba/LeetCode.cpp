#include "leetcode/problems/integer-replacement.h"

namespace leetcode::problem_397 {

namespace {

int integerReplacementImpl(int n) {
    long long x = n;
    int ops = 0;
    while (x != 1) {
        if ((x & 1) == 0) {
            x >>= 1;
        } else {
            // Odd. Special case x == 3: 3 -> 2 -> 1 is optimal (2 steps).
            if (x == 3 || (x & 3) == 1) {
                --x;
            } else {
                ++x;
            }
        }
        ++ops;
    }
    return ops;
}

}  // namespace

IntegerReplacementSolution::IntegerReplacementSolution() {
    setMetaInfo({397, "Integer Replacement",
                  "https://leetcode.com/problems/integer-replacement/"});
    registerStrategy({.name = "greedyBitManipulation",
                      .expected = "Accepted",
                      .time_complexity = "O(log n)",
                      .space_complexity = "O(1)",
                      .tags = {"Greedy", "Bit Manipulation"}},
                     integerReplacementImpl);
}

int IntegerReplacementSolution::integerReplacement(int n) {
    return getSolution()(n);
}

}  // namespace leetcode::problem_397
