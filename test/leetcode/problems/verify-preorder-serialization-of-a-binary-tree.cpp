#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/verify-preorder-serialization-of-a-binary-tree.h"

namespace leetcode {
namespace problem_331 {

class VerifyPreorderSerializationOfABinaryTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  VerifyPreorderSerializationOfABinaryTreeSolution solution;
};

TEST_P(VerifyPreorderSerializationOfABinaryTreeTest, Example1) {
  EXPECT_TRUE(solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
}

TEST_P(VerifyPreorderSerializationOfABinaryTreeTest, Example2) {
  EXPECT_FALSE(solution.isValidSerialization("1,#"));
}

TEST_P(VerifyPreorderSerializationOfABinaryTreeTest, Example3) {
  EXPECT_FALSE(solution.isValidSerialization("9,#,#,1"));
}

// SelfAuthored
TEST_P(VerifyPreorderSerializationOfABinaryTreeTest, SelfAuthoredSingleNull) {
  EXPECT_TRUE(solution.isValidSerialization("#"));
}

TEST_P(VerifyPreorderSerializationOfABinaryTreeTest, SelfAuthoredSingleNodeNoChildren) {
  // "1,#,#" represents a leaf node with two null children.
  EXPECT_TRUE(solution.isValidSerialization("1,#,#"));
}

TEST_P(VerifyPreorderSerializationOfABinaryTreeTest, SelfAuthoredRootThenRightChildOnlyIllegal) {
  // "1,#,2,#,#" would be valid (root with one right child).
  // But "1,#" is malformed: after root, only one slot consumed with one '#'.
  EXPECT_FALSE(solution.isValidSerialization("1,#"));
}

INSTANTIATE_TEST_SUITE_P(
    VerifyPreorderSerializationOfABinaryTreeTestSuite,
    VerifyPreorderSerializationOfABinaryTreeTest,
    ::testing::ValuesIn(
        VerifyPreorderSerializationOfABinaryTreeSolution().getStrategyNames()));

}  // namespace problem_331
}  // namespace leetcode
