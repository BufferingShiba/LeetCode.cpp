#include "leetcode/problems/self-dividing-numbers.h"

namespace leetcode {
namespace problem_728 {

namespace {

bool isSelfDividing(int n) {
  int num = n;
  while (num > 0) {
    int digit = num % 10;
    if (digit == 0 || n % digit != 0) {
      return false;
    }
    num /= 10;
  }
  return true;
}

std::vector<int> selfDividingNumbersImpl(int left, int right) {
  std::vector<int> result;
  for (int i = left; i <= right; ++i) {
    if (isSelfDividing(i)) {
      result.push_back(i);
    }
  }
  return result;
}

}  // namespace

SelfDividingNumbersSolution::SelfDividingNumbersSolution() {
  setMetaInfo({.id = 728,
               .title = "Self Dividing Numbers",
               .url = "https://leetcode.com/problems/self-dividing-numbers/"});

  registerStrategy(
      {.name = "brute-force-digit-check",
       .expected = "Accepted",
       .time_complexity = "O((right-left) * d) where d <= 5",
       .space_complexity = "O(1) excluding output",
       .tags = {"Math", "Brute Force"}},
      selfDividingNumbersImpl);
}

std::vector<int> SelfDividingNumbersSolution::selfDividingNumbers(int left,
                                                                 int right) {
  return getSolution()(left, right);
}

}  // namespace problem_728
}  // namespace leetcode
