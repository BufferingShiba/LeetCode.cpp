#include <gtest/gtest.h>

#include "leetcode/problems/find-the-longest-valid-obstacle-course-at-each-position.h"

namespace leetcode {
namespace problem_1964 {

class FindTheLongestValidObstacleCourseAtEachPositionTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheLongestValidObstacleCourseAtEachPositionSolution solution_;
};

TEST_P(FindTheLongestValidObstacleCourseAtEachPositionTest, Example1) {
  std::vector<int> obstacles = {1, 2, 3, 2};
  std::vector<int> expected = {1, 2, 3, 3};
  EXPECT_EQ(solution_.longestObstacleCourseAtEachPosition(obstacles), expected);
}

TEST_P(FindTheLongestValidObstacleCourseAtEachPositionTest, Example2) {
  std::vector<int> obstacles = {2, 2, 1};
  std::vector<int> expected = {1, 2, 1};
  EXPECT_EQ(solution_.longestObstacleCourseAtEachPosition(obstacles), expected);
}

TEST_P(FindTheLongestValidObstacleCourseAtEachPositionTest, Example3) {
  std::vector<int> obstacles = {3, 1, 5, 6, 4, 2};
  std::vector<int> expected = {1, 1, 2, 3, 2, 2};
  EXPECT_EQ(solution_.longestObstacleCourseAtEachPosition(obstacles), expected);
}

TEST_P(FindTheLongestValidObstacleCourseAtEachPositionTest, SelfAuthoredSingleElement) {
  std::vector<int> obstacles = {5};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution_.longestObstacleCourseAtEachPosition(obstacles), expected);
}

TEST_P(FindTheLongestValidObstacleCourseAtEachPositionTest, SelfAuthoredAllEqual) {
  std::vector<int> obstacles = {7, 7, 7, 7};
  std::vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(solution_.longestObstacleCourseAtEachPosition(obstacles), expected);
}

TEST_P(FindTheLongestValidObstacleCourseAtEachPositionTest, SelfAuthoredStrictlyDecreasing) {
  std::vector<int> obstacles = {5, 4, 3, 2, 1};
  std::vector<int> expected = {1, 1, 1, 1, 1};
  EXPECT_EQ(solution_.longestObstacleCourseAtEachPosition(obstacles), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheLongestValidObstacleCourseAtEachPositionTest,
    testing::ValuesIn(
        FindTheLongestValidObstacleCourseAtEachPositionSolution()
            .getStrategyNames()));

}  // namespace problem_1964
}  // namespace leetcode
