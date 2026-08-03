#include "leetcode/problems/find-the-most-common-response.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3527 {

class FindTheMostCommonResponseTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheMostCommonResponseSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  responses = [["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]
// Output: "good"
TEST_P(FindTheMostCommonResponseTest, OfficialExample1) {
  std::vector<std::vector<std::string>> responses = {{"good", "ok", "good", "ok"}, {"ok", "bad", "good", "ok", "ok"}, {"good"}, {"bad"}};
  EXPECT_EQ("good", solution.findCommonResponse(responses));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  responses = [["good","ok","good"],["ok","bad"],["bad","notsure"],["great","good"]]
// Output: "bad"
TEST_P(FindTheMostCommonResponseTest, OfficialExample2) {
  std::vector<std::vector<std::string>> responses = {{"good", "ok", "good"}, {"ok", "bad"}, {"bad", "notsure"}, {"great", "good"}};
  EXPECT_EQ("bad", solution.findCommonResponse(responses));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindTheMostCommonResponseTest,
    ::testing::ValuesIn(FindTheMostCommonResponseSolution().getStrategyNames()));

}  // namespace problem_3527
}  // namespace leetcode
