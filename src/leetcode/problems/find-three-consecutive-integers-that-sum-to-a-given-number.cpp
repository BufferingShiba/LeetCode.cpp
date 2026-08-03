#include "leetcode/problems/find-three-consecutive-integers-that-sum-to-a-given-number.h"

namespace leetcode {
namespace problem_2177 {

static std::vector<long long> sumOfThreeImpl(long long num) {
  if (num % 3 != 0) {
    return {};
  }
  long long mid = num / 3;
  return {mid - 1, mid, mid + 1};
}

FindThreeConsecutiveIntegersThatSumToAGivenNumberSolution::FindThreeConsecutiveIntegersThatSumToAGivenNumberSolution() {
  setMetaInfo({.id = 2177, .title = "Find Three Consecutive Integers That Sum to a Given Number", .url = "https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/"});
  registerStrategy({.name = "math", .expected = "Accepted", .time_complexity = "O(1)", .space_complexity = "O(1)", .tags = {"Math", "Simulation"}}, sumOfThreeImpl);
  setDefaultStrategy();
}

std::vector<long long> FindThreeConsecutiveIntegersThatSumToAGivenNumberSolution::sumOfThree(long long num) {
  return getSolution()(num);
}

}  // namespace problem_2177
}  // namespace leetcode
