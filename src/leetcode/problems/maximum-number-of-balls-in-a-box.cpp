#include "leetcode/problems/maximum-number-of-balls-in-a-box.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_1742 {

namespace {

int countBallsImpl(int lowLimit, int highLimit) {
  std::unordered_map<int, int> boxCount;
  int maxCount = 0;
  for (int n = lowLimit; n <= highLimit; ++n) {
    int x = n;
    int sum = 0;
    while (x > 0) {
      sum += x % 10;
      x /= 10;
    }
    int& count = boxCount[sum];
    ++count;
    maxCount = std::max(maxCount, count);
  }
  return maxCount;
}

}  // namespace

MaximumNumberOfBallsInABoxSolution::MaximumNumberOfBallsInABoxSolution() {
  setMetaInfo({.id = 1742,
               .title = "Maximum Number of Balls in a Box",
               .url = "https://leetcode.com/problems/maximum-number-of-balls-in-a-box/"});
  registerStrategy(
      {.name = "hash_counting",
       .expected = "Accepted",
       .time_complexity = "O(n * log10(highLimit))",
       .space_complexity = "O(log10(highLimit))",
       .tags = {"Hash Table", "Counting"}},
      countBallsImpl);
}

int MaximumNumberOfBallsInABoxSolution::countBalls(int lowLimit,
                                                   int highLimit) {
  return getSolution()(lowLimit, highLimit);
}

}  // namespace problem_1742
}  // namespace leetcode
