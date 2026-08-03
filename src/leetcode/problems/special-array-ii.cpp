#include <vector>

#include "leetcode/problems/special-array-ii.h"

namespace leetcode::problem_3152 {
namespace {

std::vector<bool> isArraySpecialImpl(std::vector<int>& nums,
                                     std::vector<std::vector<int>>& queries) {
  const int n = static_cast<int>(nums.size());
  std::vector<int> prefix(n, 0);
  for (int i = 0; i + 1 < n; ++i) {
    int bad = 0;
    if (((nums[i] ^ nums[i + 1]) & 1) == 0) {
      bad = 1;  // same parity
    }
    prefix[i + 1] = prefix[i] + bad;
  }

  std::vector<bool> answer;
  answer.reserve(queries.size());
  for (const auto& q : queries) {
    const int from = q[0];
    const int to = q[1];
    // adjacent pairs in [from, to] are indexed by their left endpoint j in
    // [from, to-1], whose prefix marker is stored at prefix[j+1].
    bool special = (prefix[to] - prefix[from]) == 0;
    answer.push_back(special);
  }
  return answer;
}

}  // namespace

SpecialArrayIiSolution::SpecialArrayIiSolution() {
  this->setMetaInfo({.id = 3152,
                     .title = "Special Array II",
                     .url = "https://leetcode.com/problems/special-array-ii/"});
  this->registerStrategy(
      {.name = "prefix-sum-of-bad-pairs",
       .expected = "Accepted",
       .time_complexity = "O(n + q)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Prefix Sum"}},
      isArraySpecialImpl);
}

}  // namespace leetcode::problem_3152
