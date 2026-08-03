#include "leetcode/problems/minimum-number-of-seconds-to-make-mountain-height-zero.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3296 {

namespace {

std::vector<std::string> StrategyNames() {
  return MinimumNumberOfSecondsToMakeMountainHeightZeroSolution()
      .getStrategyNames();
}

}  // namespace

class MinimumNumberOfSecondsToMakeMountainHeightZeroTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumNumberOfSecondsToMakeMountainHeightZeroSolution solution_;
};

TEST_P(MinimumNumberOfSecondsToMakeMountainHeightZeroTest, Example1) {
  int mountainHeight = 4;
  std::vector<int> workerTimes = {2, 1, 1};
  EXPECT_EQ(3, solution_.minNumberOfSeconds(mountainHeight, workerTimes));
}

TEST_P(MinimumNumberOfSecondsToMakeMountainHeightZeroTest, Example2) {
  int mountainHeight = 10;
  std::vector<int> workerTimes = {3, 2, 2, 4};
  EXPECT_EQ(12, solution_.minNumberOfSeconds(mountainHeight, workerTimes));
}

TEST_P(MinimumNumberOfSecondsToMakeMountainHeightZeroTest, Example3) {
  int mountainHeight = 5;
  std::vector<int> workerTimes = {1};
  EXPECT_EQ(15, solution_.minNumberOfSeconds(mountainHeight, workerTimes));
}

TEST_P(MinimumNumberOfSecondsToMakeMountainHeightZeroTest, SelfAuthoredSingleFastWorker) {
  int mountainHeight = 1;
  std::vector<int> workerTimes = {5};
  EXPECT_EQ(5, solution_.minNumberOfSeconds(mountainHeight, workerTimes));
}

TEST_P(MinimumNumberOfSecondsToMakeMountainHeightZeroTest, SelfAuthoredManyWorkersEachOne) {
  int mountainHeight = 6;
  std::vector<int> workerTimes = {1, 1, 1};  // 3 workers, height 6
  // 3*1 + 3*2 = 9; each worker does 2 units -> 1 + 2 = 3 sec each, total 6 units.
  EXPECT_EQ(3, solution_.minNumberOfSeconds(mountainHeight, workerTimes));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfSecondsToMakeMountainHeightZeroTest,
    MinimumNumberOfSecondsToMakeMountainHeightZeroTest,
    ::testing::ValuesIn(StrategyNames()));

}  // namespace problem_3296
}  // namespace leetcode
