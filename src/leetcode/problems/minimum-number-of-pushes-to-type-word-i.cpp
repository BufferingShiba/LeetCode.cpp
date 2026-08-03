#include "leetcode/problems/minimum-number-of-pushes-to-type-word-i.h"

namespace leetcode {
namespace problem_3014 {

namespace {

// Greedy: with 8 keys (2-9), each key can host multiple letters at
// different push levels. Letters placed earlier on a key cost fewer
// pushes. To minimize total pushes, place letters evenly so each of the
// first 8 letters costs 1 push, next 8 cost 2, next 8 cost 3, and the
// remaining cost 4 (since there are at most 26 distinct letters).
int minimumPushesImpl(const std::string& word) {
  const int n = static_cast<int>(word.size());
  int pushes = 0;
  int level = 1;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && i % 8 == 0) {
      ++level;
    }
    pushes += level;
  }
  return pushes;
}

}  // namespace

MinimumNumberOfPushesToTypeWordISolution::
    MinimumNumberOfPushesToTypeWordISolution() {
  setMetaInfo({.id = 3014,
               .title = "Minimum Number of Pushes to Type Word I",
               .url = "https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/"});
  registerStrategy({.name = "Greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "String", "Greedy"}},
                   minimumPushesImpl);
}

int MinimumNumberOfPushesToTypeWordISolution::minimumPushes(std::string word) {
  return getSolution()(std::move(word));
}

}  // namespace problem_3014
}  // namespace leetcode
