#include "leetcode/problems/count-ways-to-group-overlapping-ranges.h"

#include <algorithm>

namespace leetcode::problem_2580 {

namespace {

int countWaysImpl(std::vector<std::vector<int>>& ranges) {
    constexpr int kMod = 1000000007;

    std::sort(ranges.begin(), ranges.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                  return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
              });

    int components = 0;
    int curStart = ranges[0][0];
    int curEnd = ranges[0][1];
    for (const auto& r : ranges) {
        if (r[0] > curEnd) {
            // new component
            ++components;
            curStart = r[0];
            curEnd = r[1];
        } else {
            curEnd = std::max(curEnd, r[1]);
        }
    }
    ++components;  // last component

    long long result = 1;
    for (int i = 0; i < components; ++i) {
        result = (result * 2) % kMod;
    }
    return static_cast<int>(result);
}

}  // namespace

CountWaysToGroupOverlappingRangesSolution::CountWaysToGroupOverlappingRangesSolution() {
    setMetaInfo({.id = 2580,
                 .title = "Count Ways to Group Overlapping Ranges",
                 .url = "https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/"});
    registerStrategy(
        {.name = "sort_and_merge",
         .expected = "Accepted",
         .time_complexity = "O(n log n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Sorting"}},
        countWaysImpl);
}

int CountWaysToGroupOverlappingRangesSolution::countWays(
    std::vector<std::vector<int>>& ranges) {
    return getSolution()(ranges);
}

}  // namespace leetcode::problem_2580
