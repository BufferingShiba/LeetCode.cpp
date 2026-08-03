#include "leetcode/problems/count-largest-group.h"

namespace leetcode::problem_1399 {

namespace {

int countLargestGroupImpl(int n) {
  std::array<int, 37> cnt{};
  int maxSize = 0;
  for (int i = 1; i <= n; ++i) {
    int v = i;
    int s = 0;
    while (v > 0) {
      s += v % 10;
      v /= 10;
    }
    ++cnt[s];
    if (cnt[s] > maxSize) maxSize = cnt[s];
  }
  int result = 0;
  for (int c : cnt) {
    if (c == maxSize) ++result;
  }
  return result;
}

}  // namespace

CountLargestGroupSolution::CountLargestGroupSolution() {
  setMetaInfo({.id = 1399, .title = "Count Largest Group", .url = "https://leetcode.com/problems/count-largest-group/"});
  registerStrategy({.name = "digit_sum_counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n * digits)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "Counting"}},
                   countLargestGroupImpl);
}

int CountLargestGroupSolution::countLargestGroup(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_1399
