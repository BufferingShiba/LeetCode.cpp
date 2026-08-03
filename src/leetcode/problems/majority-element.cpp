#include "leetcode/problems/majority-element.h"

namespace leetcode::problem_169 {

namespace {

// Boyer-Moore Voting Algorithm.
// Because a majority element (> n/2 occurrences) is guaranteed to exist,
// the candidate left standing after cancellation is the answer.
int majorityElementImpl(std::vector<int>& nums) {
  int candidate = 0;
  int count = 0;
  for (int num : nums) {
    if (count == 0) {
      candidate = num;
    }
    count += (num == candidate) ? 1 : -1;
  }
  return candidate;
}

}  // namespace

MajorityElementSolution::MajorityElementSolution() {
  setMetaInfo({.id = 169,
               .title = "Majority Element",
               .url = "https://leetcode.com/problems/majority-element/"});
  registerStrategy({.name = "BoyerMooreVoting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Counting"}},
                   majorityElementImpl);
}

int MajorityElementSolution::majorityElement(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_169
