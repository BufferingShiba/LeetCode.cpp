#include "leetcode/problems/minimum-number-of-days-to-make-m-bouquets.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1482 {
namespace {

class MinimumNumberOfDaysToMakeMBouquetsTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 public:
  MinimumNumberOfDaysToMakeMBouquetsSolution solution_;
};

TEST_P(MinimumNumberOfDaysToMakeMBouquetsTest, Example1) {
  std::vector<int> bloomDay = {1, 10, 3, 10, 2};
  EXPECT_EQ(3, solution_.minDays(bloomDay, 3, 1));
}

TEST_P(MinimumNumberOfDaysToMakeMBouquetsTest, Example2) {
  std::vector<int> bloomDay = {1, 10, 3, 10, 2};
  EXPECT_EQ(-1, solution_.minDays(bloomDay, 3, 2));
}

TEST_P(MinimumNumberOfDaysToMakeMBouquetsTest, Example3) {
  std::vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
  EXPECT_EQ(12, solution_.minDays(bloomDay, 2, 3));
}

TEST_P(MinimumNumberOfDaysToMakeMBouquetsTest, SelfAuthoredSingleBouquetSingleFlower) {
  std::vector<int> bloomDay = {5};
  EXPECT_EQ(5, solution_.minDays(bloomDay, 1, 1));
}

TEST_P(MinimumNumberOfDaysToMakeMBouquetsTest, SelfAuthoredNotEnoughFlowers) {
  std::vector<int> bloomDay = {2, 5};
  EXPECT_EQ(-1, solution_.minDays(bloomDay, 2, 2));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfDaysToMakeMBouquetsTestSuite,
    MinimumNumberOfDaysToMakeMBouquetsTest,
    ::testing::ValuesIn(MinimumNumberOfDaysToMakeMBouquetsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1482
}  // namespace leetcode
