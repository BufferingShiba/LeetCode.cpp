#include <gtest/gtest.h>

#include "leetcode/problems/remove-duplicates-from-sorted-array-ii.h"

#include <string>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_80 {
namespace {

void RunCase(const std::string& strategy, std::vector<int> input,
             const std::vector<int>& expected) {
  RemoveDuplicatesFromSortedArrayIiSolution solution;
  solution.setStrategy(strategy);
  int k = solution.getSolution()(input);
  EXPECT_EQ(k, (int)expected.size());
  for (int i = 0; i < k; ++i) {
    EXPECT_EQ(input[i], expected[i]);
  }
}

}  // namespace

class RemoveDuplicatesFromSortedArrayIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { strategy_ = GetParam(); }
  std::string strategy_;
};

TEST_P(RemoveDuplicatesFromSortedArrayIiTest, OfficialExample1) {
  RunCase(strategy_, {1, 1, 1, 2, 2, 3}, {1, 1, 2, 2, 3});
}

TEST_P(RemoveDuplicatesFromSortedArrayIiTest, OfficialExample2) {
  RunCase(strategy_, {0, 0, 1, 1, 1, 1, 2, 3, 3}, {0, 0, 1, 1, 2, 3, 3});
}

TEST_P(RemoveDuplicatesFromSortedArrayIiTest, SelfAuthoredEdgeSingleElement) {
  RunCase(strategy_, {1}, {1});
}

TEST_P(RemoveDuplicatesFromSortedArrayIiTest, SelfAuthoredEdgeTwoEqual) {
  RunCase(strategy_, {1, 1}, {1, 1});
}

TEST_P(RemoveDuplicatesFromSortedArrayIiTest, SelfAuthoredEdgeThreeEqual) {
  RunCase(strategy_, {1, 1, 1}, {1, 1});
}

TEST_P(RemoveDuplicatesFromSortedArrayIiTest, SelfAuthoredEdgeAllDistinct) {
  RunCase(strategy_, {1, 2, 3}, {1, 2, 3});
}

TEST_P(RemoveDuplicatesFromSortedArrayIiTest, SelfAuthoredMixedDuplicates) {
  RunCase(strategy_, {1, 1, 2, 2, 2, 3, 3, 3, 3}, {1, 1, 2, 2, 3, 3});
}

INSTANTIATE_TEST_SUITE_P(
    RemoveDuplicatesFromSortedArrayIiTestCases,
    RemoveDuplicatesFromSortedArrayIiTest,
    ::testing::ValuesIn(
        RemoveDuplicatesFromSortedArrayIiSolution().getStrategyNames()));

}  // namespace problem_80
}  // namespace leetcode
