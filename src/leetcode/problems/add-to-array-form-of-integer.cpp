#include "leetcode/problems/add-to-array-form-of-integer.h"

#include <vector>

namespace leetcode {
namespace problem_989 {
namespace {

std::vector<int> addToArrayFormImpl(std::vector<int>& num, int k) {
  std::vector<int> result;
  int carry = k;
  int i = static_cast<int>(num.size()) - 1;
  while (i >= 0 || carry > 0) {
    int sum = carry;
    if (i >= 0) {
      sum += num[i];
      --i;
    }
    result.push_back(sum % 10);
    carry = sum / 10;
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

AddToArrayFormOfIntegerSolution::AddToArrayFormOfIntegerSolution() {
  setMetaInfo({.id = 989,
               .title = "Add to Array-Form of Integer",
               .url = "https://leetcode.com/problems/add-to-array-form-of-integer/"});
  registerStrategy({.name =
                        "Iterative Addition with Carry",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Math"}},
                   addToArrayFormImpl);
}

std::vector<int> AddToArrayFormOfIntegerSolution::addToArrayForm(
    std::vector<int>& num, int k) {
  return getSolution()(num, k);
}

}  // namespace problem_989
}  // namespace leetcode
