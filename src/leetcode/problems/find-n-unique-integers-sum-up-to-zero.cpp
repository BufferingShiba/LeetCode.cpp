#include "leetcode/problems/find-n-unique-integers-sum-up-to-zero.h"

namespace leetcode {
namespace problem_1304 {
namespace {

std::vector<int> sumZeroImpl(int n) {
  std::vector<int> result;
  result.reserve(n);
  for (int i = 1; i <= n / 2; ++i) {
    result.push_back(i);
    result.push_back(-i);
  }
  if (n % 2 == 1) {
    result.push_back(0);
  }
  return result;
}

}  // namespace

FindNUniqueIntegersSumUpToZeroSolution::FindNUniqueIntegersSumUpToZeroSolution() {
  setMetaInfo({.id = 1304,
               .title = "Find N Unique Integers Sum up to Zero",
               .url = "https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/"});
  registerStrategy({.name = "pair-sum-zero",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Math"}},
                   sumZeroImpl);
}

std::vector<int> FindNUniqueIntegersSumUpToZeroSolution::sumZero(int n) {
  return getSolution()(n);
}

}  // namespace problem_1304
}  // namespace leetcode
