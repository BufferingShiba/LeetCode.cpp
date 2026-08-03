#include "leetcode/problems/count-special-quadruplets.h"

namespace leetcode {
namespace problem_1995 {

namespace {

int countQuadrupletsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int count = 0;
  for (int a = 0; a < n; ++a) {
    for (int b = a + 1; b < n; ++b) {
      for (int c = b + 1; c < n; ++c) {
        const int sum = nums[a] + nums[b] + nums[c];
        for (int d = c + 1; d < n; ++d) {
          if (nums[d] == sum) {
            ++count;
          }
        }
      }
    }
  }
  return count;
}

}  // namespace

CountSpecialQuadrupletsSolution::CountSpecialQuadrupletsSolution() {
  setMetaInfo({.id = 1995,
               .title = "Count Special Quadruplets",
               .url = "https://leetcode.com/problems/count-special-quadruplets/"});
  registerStrategy(
      {"BruteForce", "Accepted", "O(n^3)", "O(1)", {"Array", "Enumeration"}},
      countQuadrupletsImpl);
}

int CountSpecialQuadrupletsSolution::countQuadruplets(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1995
}  // namespace leetcode
