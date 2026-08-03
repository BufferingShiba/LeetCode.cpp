#include "leetcode/problems/count-pairs-that-form-a-complete-day-i.h"

#include <array>
#include <vector>

namespace leetcode::problem_3184 {

namespace {

int countCompleteDayPairsImpl(std::vector<int>& hours) {
  std::array<long long, 24> count{};
  long long pairs = 0;
  for (int h : hours) {
    int rem = h % 24;
    pairs += count[(24 - rem) % 24];
    ++count[rem];
  }
  return static_cast<int>(pairs);
}

}  // namespace

CountPairsThatFormACompleteDayISolution::CountPairsThatFormACompleteDayISolution() {
  setMetaInfo({.id = 3184,
               .title = "Count Pairs That Form a Complete Day I",
               .url = "https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/"});
  registerStrategy({.name = "hash-count",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Hash Table", "Counting"}},
                   countCompleteDayPairsImpl);
}

int CountPairsThatFormACompleteDayISolution::countCompleteDayPairs(std::vector<int>& hours) {
  return getSolution()(hours);
}

}  // namespace leetcode::problem_3184
