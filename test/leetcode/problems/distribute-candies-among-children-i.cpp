#include <gtest/gtest.h>

#include "leetcode/problems/distribute-candies-among-children-i.h"

namespace leetcode {
namespace problem_2928 {

class DistributeCandiesAmongChildrenITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DistributeCandiesAmongChildrenISolution solution;
};

TEST_P(DistributeCandiesAmongChildrenITest, Example1) {
  EXPECT_EQ(solution.distributeCandies(5, 2), 3);
}

TEST_P(DistributeCandiesAmongChildrenITest, Example2) {
  EXPECT_EQ(solution.distributeCandies(3, 3), 10);
}

TEST_P(DistributeCandiesAmongChildrenITest, SelfAuthoredLimitGreaterThanN) {
  EXPECT_EQ(solution.distributeCandies(1, 50), 3);
}

INSTANTIATE_TEST_SUITE_P(
    DistributeCandiesAmongChildrenI, DistributeCandiesAmongChildrenITest,
    ::testing::ValuesIn(
        DistributeCandiesAmongChildrenISolution().getStrategyNames()));

}  // namespace problem_2928
}  // namespace leetcode
