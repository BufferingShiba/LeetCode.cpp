#include "leetcode/problems/count-pairs-that-form-a-complete-day-ii.h"

namespace {

long long countCompleteDayPairsImpl(std::vector<int>& hours) {
  std::vector<int> freq(24, 0);
  long long ans = 0;
  for (int h : hours) {
    int r = h % 24;
    int complement = (24 - r) % 24;
    ans += freq[complement];
    freq[r]++;
  }
  return ans;
}

}  // namespace

namespace leetcode::problem_3185 {

CountPairsThatFormACompleteDayIiSolution::CountPairsThatFormACompleteDayIiSolution() {
  setMetaInfo({.id = 3185,
               .title = "Count Pairs That Form a Complete Day II",
               .url = "https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/"});
  registerStrategy({.name = "ModuloCounting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Hash Table", "Counting"}},
                   countCompleteDayPairsImpl);
  setDefaultStrategy();
}

long long CountPairsThatFormACompleteDayIiSolution::countCompleteDayPairs(
    std::vector<int>& hours) {
  return getSolution()(hours);
}

}  // namespace leetcode::problem_3185
