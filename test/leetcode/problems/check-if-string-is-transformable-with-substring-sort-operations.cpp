#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-string-is-transformable-with-substring-sort-operations.h"

namespace leetcode::problem_1585 {

using CheckIfStringIsTransformableWithSubstringSortOperationsTest =
    ::testing::TestWithParam<std::string>;

class CheckIfStringIsTransformableWithSubstringSortOperationsSolutionTest
    : public CheckIfStringIsTransformableWithSubstringSortOperationsTest {
 protected:
  CheckIfStringIsTransformableWithSubstringSortOperationsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CheckIfStringIsTransformableWithSubstringSortOperationsSolutionTest,
       Example1) {
  EXPECT_TRUE(solution.isTransformable("84532", "34852"));
}

TEST_P(CheckIfStringIsTransformableWithSubstringSortOperationsSolutionTest,
       Example2) {
  EXPECT_TRUE(solution.isTransformable("34521", "23415"));
}

TEST_P(CheckIfStringIsTransformableWithSubstringSortOperationsSolutionTest,
       Example3) {
  EXPECT_FALSE(solution.isTransformable("12345", "12435"));
}

TEST_P(CheckIfStringIsTransformableWithSubstringSortOperationsSolutionTest,
       SelfAuthoredSameString) {
  EXPECT_TRUE(solution.isTransformable("98765", "98765"));
}

TEST_P(CheckIfStringIsTransformableWithSubstringSortOperationsSolutionTest,
       SelfAuthoredSingleChar) {
  EXPECT_TRUE(solution.isTransformable("0", "0"));
  EXPECT_FALSE(solution.isTransformable("0", "1"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfStringIsTransformableWithSubstringSortOperationsTest,
    CheckIfStringIsTransformableWithSubstringSortOperationsSolutionTest,
    ::testing::ValuesIn(
        CheckIfStringIsTransformableWithSubstringSortOperationsSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1585
