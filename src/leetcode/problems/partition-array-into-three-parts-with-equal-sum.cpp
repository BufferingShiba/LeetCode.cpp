#include "leetcode/problems/partition-array-into-three-parts-with-equal-sum.h"

namespace leetcode::problem_1013 {

namespace {

bool canThreePartsEqualSumImpl(std::vector<int>& arr) {
    int total = 0;
    for (int v : arr) {
        total += v;
    }
    if (total % 3 != 0) {
        return false;
    }
    const int target = total / 3;
    int cur = 0;
    int count = 0;
    for (int v : arr) {
        cur += v;
        if (cur == target) {
            ++count;
            cur = 0;
        }
    }
    return count >= 3;
}

}  // namespace

PartitionArrayIntoThreePartsWithEqualSumSolution::
    PartitionArrayIntoThreePartsWithEqualSumSolution() {
    setMetaInfo({.id = 1013,
                 .title = "Partition Array Into Three Parts With Equal Sum",
                 .url = "https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/"});
    registerStrategy({.name = "Greedy",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Greedy"}},
                     canThreePartsEqualSumImpl);
}

bool PartitionArrayIntoThreePartsWithEqualSumSolution::
    canThreePartsEqualSum(std::vector<int>& arr) {
    return getSolution()(arr);
}

}  // namespace leetcode::problem_1013
