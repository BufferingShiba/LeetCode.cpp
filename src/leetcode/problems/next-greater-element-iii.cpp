#include "leetcode/problems/next-greater-element-iii.h"

#include <algorithm>
#include <limits>
#include <vector>

namespace leetcode {
namespace problem_556 {

namespace {

int nextGreaterElementImpl(int n) {
  if (n < 10) return -1;
  std::vector<int> digits;
  int t = n;
  while (t > 0) {
    digits.push_back(t % 10);
    t /= 10;
  }
  std::reverse(digits.begin(), digits.end());

  int i = static_cast<int>(digits.size()) - 2;
  while (i >= 0 && digits[i] >= digits[i + 1]) {
    --i;
  }
  if (i < 0) return -1;  // digits are non-increasing

  int j = static_cast<int>(digits.size()) - 1;
  while (digits[j] <= digits[i]) {
    --j;
  }
  std::swap(digits[i], digits[j]);
  std::reverse(digits.begin() + i + 1, digits.end());

  long long result = 0;
  for (int d : digits) {
    result = result * 10 + d;
    if (result > std::numeric_limits<int>::max()) return -1;
  }
  return static_cast<int>(result);
}

}  // namespace

NextGreaterElementIiiSolution::NextGreaterElementIiiSolution() {
  setMetaInfo({.id = 556,
               .title = "Next Greater Element III",
               .url = "https://leetcode.com/problems/next-greater-element-iii/"});
  registerStrategy({"NextPermutation", "Accepted", "O(len)", "O(len)",
                     {"Math", "Two Pointers", "String"}},
                    nextGreaterElementImpl);
}

int NextGreaterElementIiiSolution::nextGreaterElement(int n) {
  return getSolution()(n);
}

}  // namespace problem_556
}  // namespace leetcode
