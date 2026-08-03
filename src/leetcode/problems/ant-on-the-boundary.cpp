#include "leetcode/problems/ant-on-the-boundary.h"

namespace {

int returnToBoundaryCountImpl(std::vector<int>& nums) {
  int prefix = 0;
  int count = 0;
  for (int num : nums) {
    prefix += num;
    if (prefix == 0) {
      ++count;
    }
  }
  return count;
}

}  // namespace

namespace leetcode {
namespace problem_3028 {

AntOnTheBoundarySolution::AntOnTheBoundarySolution() {
  setMetaInfo({.id = 3028,
               .title = "Ant on the Boundary",
               .url = "https://leetcode.com/problems/ant-on-the-boundary/"});
  registerStrategy(
      {.name = "PrefixSum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Simulation", "Prefix Sum"}},
      returnToBoundaryCountImpl);
}

int AntOnTheBoundarySolution::returnToBoundaryCount(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3028
}  // namespace leetcode
