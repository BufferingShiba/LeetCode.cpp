#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/maximum-candies-you-can-get-from-boxes.h"

namespace leetcode {
namespace problem_1298 {

class MaximumCandiesYouCanGetFromBoxesTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumCandiesYouCanGetFromBoxesSolution solution_;
};

TEST_P(MaximumCandiesYouCanGetFromBoxesTest, Example1) {
  std::vector<int> status = {1, 0, 1, 0};
  std::vector<int> candies = {7, 5, 4, 100};
  std::vector<std::vector<int>> keys = {{}, {}, {1}, {}};
  std::vector<std::vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
  std::vector<int> initialBoxes = {0};

  int result = solution_.maxCandies(status, candies, keys, containedBoxes,
                                    initialBoxes);
  EXPECT_EQ(result, 16);
}

TEST_P(MaximumCandiesYouCanGetFromBoxesTest, Example2) {
  std::vector<int> status = {1, 0, 0, 0, 0, 0};
  std::vector<int> candies = {1, 1, 1, 1, 1, 1};
  std::vector<std::vector<int>> keys = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
  std::vector<std::vector<int>> containedBoxes = {
      {1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
  std::vector<int> initialBoxes = {0};

  int result = solution_.maxCandies(status, candies, keys, containedBoxes,
                                    initialBoxes);
  EXPECT_EQ(result, 6);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximumCandiesYouCanGetFromBoxesTest,
    testing::ValuesIn(
        MaximumCandiesYouCanGetFromBoxesSolution().getStrategyNames()));

}  // namespace problem_1298
}  // namespace leetcode
