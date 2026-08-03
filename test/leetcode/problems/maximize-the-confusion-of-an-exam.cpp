#include "leetcode/problems/maximize-the-confusion-of-an-exam.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2024 {

class MaximizeTheConfusionOfAnExamTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximizeTheConfusionOfAnExamSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  answerKey = "TTFF", k = 2
// Output: 4
TEST_P(MaximizeTheConfusionOfAnExamTest, OfficialExample1) {
  std::string answerKey = "TTFF";
  int k = 2;
  int result = solution.maxConsecutiveAnswers(answerKey, k);
  EXPECT_EQ(4, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  answerKey = "TFFT", k = 1
// Output: 3
TEST_P(MaximizeTheConfusionOfAnExamTest, OfficialExample2) {
  std::string answerKey = "TFFT";
  int k = 1;
  int result = solution.maxConsecutiveAnswers(answerKey, k);
  EXPECT_EQ(3, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  answerKey = "TTFTTFTT", k = 1
// Output: 5
TEST_P(MaximizeTheConfusionOfAnExamTest, OfficialExample3) {
  std::string answerKey = "TTFTTFTT";
  int k = 1;
  int result = solution.maxConsecutiveAnswers(answerKey, k);
  EXPECT_EQ(5, result);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximizeTheConfusionOfAnExamTest,
    ::testing::ValuesIn(MaximizeTheConfusionOfAnExamSolution().getStrategyNames()));

}  // namespace problem_2024
}  // namespace leetcode
