#include "leetcode/problems/last-visited-integers.h"

namespace leetcode {
namespace problem_2899 {

namespace {

std::vector<int> lastVisitedIntegersImpl(std::vector<int>& nums) {
  std::vector<int> seen;
  std::vector<int> ans;
  int k = 0;
  for (int x : nums) {
    if (x != -1) {
      seen.insert(seen.begin(), x);
      k = 0;
    } else {
      ++k;
      if (k <= static_cast<int>(seen.size())) {
        ans.push_back(seen[k - 1]);
      } else {
        ans.push_back(-1);
      }
    }
  }
  return ans;
}

}  // namespace

LastVisitedIntegersSolution::LastVisitedIntegersSolution() {
  setMetaInfo({
      .id = 2899,
      .title = "Last Visited Integers",
      .url = "https://leetcode.com/problems/last-visited-integers/",
  });
  registerStrategy(
      {
          .name = "simulation",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(n)",
          .tags = {"Array", "Simulation"},
      },
      lastVisitedIntegersImpl);
}

std::vector<int> LastVisitedIntegersSolution::lastVisitedIntegers(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2899
}  // namespace leetcode
