#include <climits>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/minimum-distance-between-three-equal-elements-i.h"

namespace leetcode {
namespace problem_3740 {

using MinimumDistanceBetweenThreeEqualElementsITest =
    ::testing::TestWithParam<std::string>;

TEST_P(MinimumDistanceBetweenThreeEqualElementsITest, Example1) {
  auto solution = MinimumDistanceBetweenThreeEqualElementsISolution();
  solution.setStrategy(GetParam());

  std::vector<int> nums = {1, 2, 1, 1, 3};
  EXPECT_EQ(solution.minimumDistance(nums), 6);
}

TEST_P(MinimumDistanceBetweenThreeEqualElementsITest, Example2) {
  auto solution = MinimumDistanceBetweenThreeEqualElementsISolution();
  solution.setStrategy(GetParam());

  std::vector<int> nums = {1, 1, 2, 3, 2, 1, 2};
  EXPECT_EQ(solution.minimumDistance(nums), 8);
}

TEST_P(MinimumDistanceBetweenThreeEqualElementsITest, Example3) {
  auto solution = MinimumDistanceBetweenThreeEqualElementsISolution();
  solution.setStrategy(GetParam());

  std::vector<int> nums = {1};
  EXPECT_EQ(solution.minimumDistance(nums), -1);
}

TEST_P(MinimumDistanceBetweenThreeEqualElementsITest, SelfAuthored) {
  auto solution = MinimumDistanceBetweenThreeEqualElementsISolution();
  solution.setStrategy(GetParam());

  {
    // only two equal elements -> no good tuple
    std::vector<int> nums = {1, 2, 1};
    EXPECT_EQ(solution.minimumDistance(nums), -1);
  }
  {
    // value 2 -> indices [0,2,4], distance = 2*(4-0) = 8
    std::vector<int> nums = {2, 1, 2, 1, 2};
    EXPECT_EQ(solution.minimumDistance(nums), 8);
  }
  {
    // value 1 -> indices [0,1,3]: 2*(3-0)=6; value 2 -> [2,4,5]: 2*(5-2)=6
    std::vector<int> nums = {1, 1, 2, 1, 2, 2};
    EXPECT_EQ(solution.minimumDistance(nums), 6);
  }
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDistanceBetweenThreeEqualElementsITests,
    MinimumDistanceBetweenThreeEqualElementsITest,
    ::testing::ValuesIn(
        MinimumDistanceBetweenThreeEqualElementsISolution().getStrategyNames()));

}  // namespace problem_3740
}  // namespace leetcode
