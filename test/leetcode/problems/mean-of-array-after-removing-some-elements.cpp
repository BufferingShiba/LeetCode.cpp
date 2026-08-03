#include <gtest/gtest.h>
#include <vector>

#include "leetcode/problems/mean-of-array-after-removing-some-elements.h"

namespace leetcode {
namespace problem_1619 {
namespace {

class MeanOfArrayAfterRemovingSomeElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MeanOfArrayAfterRemovingSomeElementsSolution solution;
};

TEST_P(MeanOfArrayAfterRemovingSomeElementsTest, Example1) {
  std::vector<int> arr = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                          2, 2, 2, 2, 2, 2, 2, 2, 3};
  EXPECT_NEAR(solution.getSolution()(arr), 2.0, 1e-5);
}

TEST_P(MeanOfArrayAfterRemovingSomeElementsTest, Example2) {
  std::vector<int> arr = {6, 2, 7, 5, 1, 2, 0, 3, 10, 2,
                          5, 0, 5, 5, 0, 8, 7, 6, 8, 0};
  EXPECT_NEAR(solution.getSolution()(arr), 4.0, 1e-5);
}

TEST_P(MeanOfArrayAfterRemovingSomeElementsTest, Example3) {
  std::vector<int> arr = {
      6, 0, 7, 0, 7, 5, 7, 8, 3, 4, 0, 7, 8, 1, 6, 8, 1, 1, 2, 4,  8, 1,
      9, 5, 4, 3, 8, 5, 10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4};
  EXPECT_NEAR(solution.getSolution()(arr), 4.77778, 1e-5);
}

TEST_P(MeanOfArrayAfterRemovingSomeElementsTest, SelfAuthoredAllSame) {
  std::vector<int> arr(20, 7);
  EXPECT_NEAR(solution.getSolution()(arr), 7.0, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(
    MeanOfArrayAfterRemovingSomeElementsTestSuite,
    MeanOfArrayAfterRemovingSomeElementsTest,
    ::testing::ValuesIn(
        MeanOfArrayAfterRemovingSomeElementsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1619
}  // namespace leetcode
