#include "leetcode/problems/minimum-deletions-for-at-most-k-distinct-characters.h"

#include <algorithm>
#include <array>

namespace leetcode {
namespace problem_3545 {

namespace {

int solveMinimumDeletions(std::string s, int k) {
  std::array<int, 26> frequency{};
  for (char c : s) {
    ++frequency[c - 'a'];
  }

  std::sort(frequency.begin(), frequency.end());
  const int distinct =
      static_cast<int>(std::count_if(frequency.begin(), frequency.end(),
                                     [](int count) { return count > 0; }));
  int deletions = 0;
  const int remove_count = distinct - k;
  const int first_positive = static_cast<int>(frequency.size()) - distinct;
  for (int i = 0; i < remove_count; ++i) {
    deletions += frequency[first_positive + i];
  }
  return deletions;
}

}  // namespace

MinimumDeletionsForAtMostKDistinctCharactersSolution::
    MinimumDeletionsForAtMostKDistinctCharactersSolution() {
  setMetaInfo({.id = 3545,
               .title = "Minimum Deletions for At Most K Distinct Characters",
               .url = "https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/"});
  registerStrategy({.name = "CountAndRemoveLeastFrequent",
                    .expected = "Accepted",
                    .time_complexity = "O(n + alphabet log alphabet)",
                    .space_complexity = "O(alphabet)",
                    .tags = {"Hash Table", "Greedy", "Sorting"}},
                   solveMinimumDeletions);
}

}  // namespace problem_3545
}  // namespace leetcode
