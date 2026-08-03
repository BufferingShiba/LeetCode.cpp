#include "leetcode/problems/count-monobit-integers.h"

namespace {

int countMonobitImpl(int n) {
    int count = 0;
    for (int k = 0; ; ++k) {
        long long val = (1LL << k) - 1;
        if (val > n) break;
        ++count;
    }
    return count;
}

}  // namespace

namespace leetcode {
namespace problem_3827 {

CountMonobitIntegersSolution::CountMonobitIntegersSolution() {
    setMetaInfo({.id = 3827, .title = "Count Monobit Integers", .url = "https://leetcode.com/problems/count-monobit-integers/"});
    registerStrategy({
        .name = "EnumeratePow2Minus1",
        .expected = "Accepted",
        .time_complexity = "O(log n)",
        .space_complexity = "O(1)",
        .tags = {"Bit Manipulation", "Enumeration"}
    }, countMonobitImpl);
}

int CountMonobitIntegersSolution::countMonobit(int n) {
    return getSolution()(n);
}

}  // namespace problem_3827
}  // namespace leetcode
