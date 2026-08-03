#include <gtest/gtest.h>

#include "leetcode/problems/find-subtree-sizes-after-changes.h"

namespace leetcode {
namespace problem_3331 {

class FindSubtreeSizesAfterChangesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  FindSubtreeSizesAfterChangesSolution solution_;
};

TEST_P(FindSubtreeSizesAfterChangesTest, Example1) {
  std::vector<int> parent = {-1, 0, 0, 1, 1, 1};
  std::string s = "abaabc";
  std::vector<int> expected = {6, 3, 1, 1, 1, 1};
  EXPECT_EQ(solution_.findSubtreeSizes(parent, s), expected);
}

TEST_P(FindSubtreeSizesAfterChangesTest, Example2) {
  std::vector<int> parent = {-1, 0, 4, 0, 1};
  std::string s = "abbba";
  std::vector<int> expected = {5, 2, 1, 1, 1};
  EXPECT_EQ(solution_.findSubtreeSizes(parent, s), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FindSubtreeSizesAfterChangesTest,
    ::testing::ValuesIn(
        FindSubtreeSizesAfterChangesSolution().getStrategyNames()));

}  // namespace problem_3331
}  // namespace leetcode
