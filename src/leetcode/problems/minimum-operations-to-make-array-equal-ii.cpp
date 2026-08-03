#include "leetcode/problems/minimum-operations-to-make-array-equal-ii.h"

namespace leetcode::problem_2541 {

namespace {

long long minOperationsImpl(std::vector<int>& nums1, std::vector<int>& nums2,
                            int k) {
  const int n = static_cast<int>(nums1.size());

  if (k == 0) {
    for (int i = 0; i < n; ++i) {
      if (nums1[i] != nums2[i]) {
        return -1;
      }
    }
    return 0;
  }

  long long positive_sum = 0;
  long long balance = 0;
  for (int i = 0; i < n; ++i) {
    long long diff = static_cast<long long>(nums1[i]) - nums2[i];
    if (diff % k != 0) {
      return -1;
    }
    if (diff > 0) {
      positive_sum += diff;
    }
    balance += diff;
  }

  if (balance != 0) {
    return -1;
  }
  return positive_sum / k;
}

}  // namespace

MinimumOperationsToMakeArrayEqualIiSolution::
    MinimumOperationsToMakeArrayEqualIiSolution() {
  this->setMetaInfo({2541,
                     "Minimum Operations to Make Array Equal II",
                     "https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/"});
  this->registerStrategy(
      {"GreedyDiff", "Accepted", "O(n)", "O(1)",
       {"Array", "Math", "Greedy"}},
      minOperationsImpl);
}

long long MinimumOperationsToMakeArrayEqualIiSolution::minOperations(
    std::vector<int>& nums1, std::vector<int>& nums2, int k) {
  return getSolution()(nums1, nums2, k);
}

}  // namespace leetcode::problem_2541
