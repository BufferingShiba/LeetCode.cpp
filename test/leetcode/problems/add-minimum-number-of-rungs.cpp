#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/add-minimum-number-of-rungs.h"

namespace leetcode {
namespace problem_1936 {

class AddMinimumNumberOfRungsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AddMinimumNumberOfRungsSolution solution;
};

TEST_P(AddMinimumNumberOfRungsTest, Example1) {
  std::vector<int> rungs = {1, 3, 5, 10};
  int dist = 2;
  EXPECT_EQ(solution.addRungs(rungs, dist), 2);
}

TEST_P(AddMinimumNumberOfRungsTest, Example2) {
  std::vector<int> rungs = {3, 6, 8, 10};
  int dist = 3;
  EXPECT_EQ(solution.addRungs(rungs, dist), 0);
}

TEST_P(AddMinimumNumberOfRungsTest, Example3) {
  std::vector<int> rungs = {3, 4, 6, 7};
  int dist = 2;
  EXPECT_EQ(solution.addRungs(rungs, dist), 1);
}

TEST_P(AddMinimumNumberOfRungsTest, SelfAuthoredSingleRungBelowDist) {
  std::vector<int> rungs = {3};
  int dist = 2;
  // gap from 0 to 3 is 3 > 2, need (3-1)/2 = 1
  EXPECT_EQ(solution.addRungs(rungs, dist), 1);
}

TEST_P(AddMinimumNumberOfRungsTest, SelfAuthoredLargeGap) {
  std::vector<int> rungs = {5, 20};
  int dist = 6;
  // gap from 5 to 20 is 15 > 6, need (15-1)/6 = 2
  EXPECT_EQ(solution.addRungs(rungs, dist), 2);
}

INSTANTIATE_TEST_SUITE_P(
    AddMinimumNumberOfRungsTestSuite, AddMinimumNumberOfRungsTest,
    ::testing::ValuesIn(AddMinimumNumberOfRungsSolution().getStrategyNames()));

}  // namespace problem_1936
}  // namespace leetcode
