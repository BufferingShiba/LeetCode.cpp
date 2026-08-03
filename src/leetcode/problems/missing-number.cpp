#include "leetcode/problems/missing-number.h"

namespace leetcode {
namespace problem_268 {

static int solution1(vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int missing = n;
  for (int i = 0; i < n; ++i) {
    missing ^= i ^ nums[i];
  }
  return missing;
}

MissingNumberSolution::MissingNumberSolution() {
  setMetaInfo({
      .id = 268,
      .title = "Missing Number",
      .url = "https://leetcode.com/problems/missing-number"
  });
  registerStrategy({.name = "XOR",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Bit Manipulation"}},
                   solution1);
}

int MissingNumberSolution::missingNumber(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_268
}  // namespace leetcode
