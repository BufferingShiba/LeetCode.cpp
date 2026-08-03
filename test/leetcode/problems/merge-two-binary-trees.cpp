#include <gtest/gtest.h>

#include "leetcode/problems/merge-two-binary-trees.h"

namespace leetcode {
namespace problem_617 {

class MergeTwoBinaryTreesTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MergeTwoBinaryTreesSolution solution_;
};

TEST_P(MergeTwoBinaryTreesTest, Example1) {
  auto* root1 = constructTree(std::vector<std::optional<int>>{1, 3, 2, 5});
  auto* root2 =
      constructTree(std::vector<std::optional<int>>{2, 1, 3, std::nullopt, 4,
                                                     std::nullopt, 7});
  auto* expected =
      constructTree(std::vector<std::optional<int>>{3, 4, 5, 5, 4, std::nullopt,
                                                     7});

  auto* result = solution_.mergeTrees(root1, root2);

  EXPECT_TRUE(isSameTree(expected, result));

  delete root1;
  delete root2;
  delete expected;
  delete result;
}

TEST_P(MergeTwoBinaryTreesTest, Example2) {
  auto* root1 = constructTree(std::vector<std::optional<int>>{1});
  auto* root2 = constructTree(std::vector<std::optional<int>>{1, 2});
  auto* expected = constructTree(std::vector<std::optional<int>>{2, 2});

  auto* result = solution_.mergeTrees(root1, root2);

  EXPECT_TRUE(isSameTree(expected, result));

  delete root1;
  delete root2;
  delete expected;
  delete result;
}

TEST_P(MergeTwoBinaryTreesTest, SelfAuthoredBothEmpty) {
  auto* result = solution_.mergeTrees(nullptr, nullptr);
  EXPECT_EQ(nullptr, result);
}

TEST_P(MergeTwoBinaryTreesTest, SelfAuthoredOneEmpty) {
  auto* root1 = constructTree(std::vector<std::optional<int>>{5, 3, 8});
  auto* expected = constructTree(std::vector<std::optional<int>>{5, 3, 8});

  auto* result = solution_.mergeTrees(root1, nullptr);
  EXPECT_TRUE(isSameTree(expected, result));

  delete root1;
  delete expected;
  delete result;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MergeTwoBinaryTreesTest,
    testing::ValuesIn(MergeTwoBinaryTreesSolution().getStrategyNames()));

}  // namespace problem_617
}  // namespace leetcode
