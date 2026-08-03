#include "leetcode/problems/special-array-i.h"

namespace leetcode {
namespace problem_3151 {

namespace {

bool isArraySpecialImpl(std::vector<int>& nums) {
  for (std::size_t i = 1; i < nums.size(); ++i) {
    if ((nums[i - 1] % 2) == (nums[i] % 2)) {
      return false;
    }
  }
  return true;
}

}  // namespace

SpecialArrayISolution::SpecialArrayISolution() {
  setMetaInfo({.id = 3151,
               .title = "Special Array I",
               .url = "https://leetcode.com/problems/special-array-i/"});

  registerStrategy(
      {.name = "linear-scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"},
       .notes = "Check parity of each adjacent pair in one pass."},
      isArraySpecialImpl);
}

bool SpecialArrayISolution::isArraySpecial(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3151
}  // namespace leetcode
