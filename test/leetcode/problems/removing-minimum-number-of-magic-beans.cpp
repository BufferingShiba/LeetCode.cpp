#include "leetcode/problems/removing-minimum-number-of-magic-beans.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_2171 {

class RemovingMinimumNumberOfMagicBeansTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemovingMinimumNumberOfMagicBeansSolution solution;
};

TEST_P(RemovingMinimumNumberOfMagicBeansTest, Example1) {
  std::vector<int> beans{4, 1, 6, 5};
  EXPECT_EQ(4, solution.minimumRemoval(beans));
}

TEST_P(RemovingMinimumNumberOfMagicBeansTest, Example2) {
  std::vector<int> beans{2, 10, 3, 2};
  EXPECT_EQ(7, solution.minimumRemoval(beans));
}

TEST_P(RemovingMinimumNumberOfMagicBeansTest, SelfAuthoredSingleBag) {
  std::vector<int> beans{5};
  EXPECT_EQ(0, solution.minimumRemoval(beans));
}

TEST_P(RemovingMinimumNumberOfMagicBeansTest, SelfAuthoredAllEqual) {
  std::vector<int> beans{3, 3, 3};
  EXPECT_EQ(0, solution.minimumRemoval(beans));
}

TEST_P(RemovingMinimumNumberOfMagicBeansTest, SelfAuthoredRemoveAllButZero) {
  // [2,10,3,2] -> optimum is emptying small bags, keep one bag of 10.
  std::vector<int> beans{2, 10, 3, 2};
  EXPECT_EQ(7, solution.minimumRemoval(beans));
}

INSTANTIATE_TEST_SUITE_P(
    RemovingMinimumNumberOfMagicBeansTestSuite,
    RemovingMinimumNumberOfMagicBeansTest,
    ::testing::ValuesIn(
        RemovingMinimumNumberOfMagicBeansSolution().getStrategyNames()));

}  // namespace leetcode::problem_2171
