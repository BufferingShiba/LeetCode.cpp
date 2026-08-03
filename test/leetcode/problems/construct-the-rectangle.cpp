#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/construct-the-rectangle.h"

namespace leetcode {
namespace problem_492 {

class ConstructTheRectangleTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConstructTheRectangleSolution solution_;
};

TEST_P(ConstructTheRectangleTest, Example1) {
  EXPECT_EQ(solution_.constructRectangle(4), std::vector<int>({2, 2}));
}

TEST_P(ConstructTheRectangleTest, Example2) {
  EXPECT_EQ(solution_.constructRectangle(37), std::vector<int>({37, 1}));
}

TEST_P(ConstructTheRectangleTest, Example3) {
  EXPECT_EQ(solution_.constructRectangle(122122), std::vector<int>({427, 286}));
}

TEST_P(ConstructTheRectangleTest, SelfAuthored) {
  EXPECT_EQ(solution_.constructRectangle(9), std::vector<int>({3, 3}));
  EXPECT_EQ(solution_.constructRectangle(2), std::vector<int>({2, 1}));
  EXPECT_EQ(solution_.constructRectangle(1), std::vector<int>({1, 1}));
}

INSTANTIATE_TEST_SUITE_P(Strategies, ConstructTheRectangleTest,
                         ::testing::ValuesIn(
                             ConstructTheRectangleSolution().getStrategyNames()));

}  // namespace problem_492
}  // namespace leetcode
