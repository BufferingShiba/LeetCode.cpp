#include "leetcode/problems/find-if-digit-game-can-be-won.h"

namespace leetcode {
namespace problem_3232 {
namespace {

bool canAliceWinImpl(std::vector<int>& nums) {
  int total = 0;
  int single = 0;
  long long doubleSum = 0;

  for (int num : nums) {
    total += num;
    if (num < 10) {
      single += num;
    } else {
      doubleSum += num;
    }
  }

  int bobSingle = total - single;
  int bobDouble = total - static_cast<int>(doubleSum);

  return single > bobSingle || doubleSum > bobDouble;
}

}  // namespace

FindIfDigitGameCanBeWonSolution::FindIfDigitGameCanBeWonSolution() {
  setMetaInfo({.id = 3232,
               .title = "Find if Digit Game Can Be Won",
               .url = "https://leetcode.com/problems/find-if-digit-game-can-be-won/"});

  registerStrategy(
      {.name = "count-single-and-double",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      canAliceWinImpl);
}

bool FindIfDigitGameCanBeWonSolution::canAliceWin(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3232
}  // namespace leetcode
