#include "leetcode/problems/check-distances-between-same-letters.h"

namespace leetcode {
namespace problem_2399 {

namespace {

bool checkDistancesImpl(std::string s, std::vector<int>& distance) {
  std::vector<int> firstPos(26, -1);
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    int idx = s[i] - 'a';
    if (firstPos[idx] == -1) {
      firstPos[idx] = i;
    } else {
      int gap = i - firstPos[idx] - 1;
      if (gap != distance[idx]) {
        return false;
      }
    }
  }
  return true;
}

}  // namespace

CheckDistancesBetweenSameLettersSolution::CheckDistancesBetweenSameLettersSolution() {
  setMetaInfo({.id = 2399,
               .title = "Check Distances Between Same Letters",
               .url = "https://leetcode.com/problems/check-distances-between-same-letters/"});
  registerStrategy(
      {.name = "hashmap-first-position",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "String"}},
      checkDistancesImpl);
}

bool CheckDistancesBetweenSameLettersSolution::checkDistances(std::string s,
                                                              std::vector<int>& distance) {
  return getSolution()(s, distance);
}

}  // namespace problem_2399
}  // namespace leetcode
