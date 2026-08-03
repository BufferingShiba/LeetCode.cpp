#include "leetcode/problems/replace-elements-with-greatest-element-on-right-side.h"

namespace {

std::vector<int> replaceElementsImpl(std::vector<int>& arr) {
  int n = static_cast<int>(arr.size());
  std::vector<int> result(n);
  int maxRight = -1;
  for (int i = n - 1; i >= 0; --i) {
    result[i] = maxRight;
    maxRight = std::max(maxRight, arr[i]);
  }
  return result;
}

}  // namespace

namespace leetcode::problem_1299 {

ReplaceElementsWithGreatestElementOnRightSideSolution::ReplaceElementsWithGreatestElementOnRightSideSolution() {
  setMetaInfo({.id = 1299, .title = "Replace Elements with Greatest Element on Right Side", .url = "https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/"});
  registerStrategy({.name = "RightToLeft", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(1)", .tags = {"Array"}}, replaceElementsImpl);
}

std::vector<int> ReplaceElementsWithGreatestElementOnRightSideSolution::replaceElements(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace leetcode::problem_1299
