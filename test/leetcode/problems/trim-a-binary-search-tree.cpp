#include <gtest/gtest.h>
#include "leetcode/problems/trim-a-binary-search-tree.h"

namespace leetcode::problem_669 {

class TrimABinarySearchTreeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  TrimABinarySearchTreeSolution solution_;
};

TEST_P(TrimABinarySearchTreeTest, Example1) {
    auto* root = constructTree(std::vector<std::optional<int>>{1, 0, 2});
    auto* expected = constructTree(std::vector<std::optional<int>>{1, std::nullopt, 2});
    auto* result = solution_.trimBST(root, 1, 2);
    EXPECT_TRUE(isSameTree(result, expected));
    delete result;
    delete expected;
}

TEST_P(TrimABinarySearchTreeTest, Example2) {
    auto* root = constructTree(std::vector<std::optional<int>>{3, 0, 4, std::nullopt, 2, std::nullopt, std::nullopt, 1});
    auto* expected = constructTree(std::vector<std::optional<int>>{3, 2, std::nullopt, 1});
    auto* result = solution_.trimBST(root, 1, 3);
    EXPECT_TRUE(isSameTree(result, expected));
    delete result;
    delete expected;
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    TrimABinarySearchTreeTest,
    testing::ValuesIn(TrimABinarySearchTreeSolution().getStrategyNames()));

}  // namespace leetcode::problem_669
