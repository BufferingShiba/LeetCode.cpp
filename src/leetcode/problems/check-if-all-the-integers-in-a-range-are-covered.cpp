#include "leetcode/problems/check-if-all-the-integers-in-a-range-are-covered.h"

namespace leetcode {
namespace problem_1893 {

static bool isCoveredImpl(std::vector<std::vector<int>>& ranges, int left, int right) {
  int diff[52] = {0};
  for (auto& r : ranges) {
    diff[r[0]]++;
    diff[r[1] + 1]--;
  }
  int covered = 0;
  for (int i = 1; i <= 50; ++i) {
    covered += diff[i];
    if (i >= left && i <= right && covered <= 0) {
      return false;
    }
  }
  return true;
}

CheckIfAllTheIntegersInARangeAreCoveredSolution::CheckIfAllTheIntegersInARangeAreCoveredSolution() {
  setMetaInfo({.id = 1893, .title = "Check if All the Integers in a Range Are Covered", .url = "https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/"});
  registerStrategy({.name = "Prefix Sum", .expected = "Accepted", .time_complexity = "O(n + R)", .space_complexity = "O(R)", .tags = {"Array", "Prefix Sum"}}, isCoveredImpl);
}

bool CheckIfAllTheIntegersInARangeAreCoveredSolution::isCovered(std::vector<std::vector<int>>& ranges, int left, int right) {
  return getSolution()(ranges, left, right);
}

}  // namespace problem_1893
}  // namespace leetcode
