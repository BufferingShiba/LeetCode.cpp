#include <gtest/gtest.h>

#include "leetcode/problems/smallest-sufficient-team.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1125 {

class SmallestSufficientTeamTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  SmallestSufficientTeamSolution solution;
};

TEST_P(SmallestSufficientTeamTest, Example1) {
  std::vector<std::string> req_skills{"java", "nodejs", "reactjs"};
  std::vector<std::vector<std::string>> people{
      {"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
  const auto answer = solution.smallestSufficientTeam(req_skills, people);
  EXPECT_EQ(2, answer.size());
  EXPECT_TRUE(std::find(answer.begin(), answer.end(), 0) != answer.end());
  EXPECT_TRUE(std::find(answer.begin(), answer.end(), 2) != answer.end());
}

TEST_P(SmallestSufficientTeamTest, Example2) {
  std::vector<std::string> req_skills{"algorithms", "math", "java", "reactjs",
                                      "csharp", "aws"};
  std::vector<std::vector<std::string>> people{
      {"algorithms", "math", "java"}, {"algorithms", "math", "reactjs"},
      {"java", "csharp", "aws"}, {"reactjs", "csharp"}};
  const auto answer = solution.smallestSufficientTeam(req_skills, people);
  EXPECT_EQ(2, answer.size());
  std::vector<int> sorted_answer = answer;
  std::sort(sorted_answer.begin(), sorted_answer.end());
  EXPECT_EQ((std::vector<int>{1, 2}), sorted_answer);
}

TEST_P(SmallestSufficientTeamTest, Example3) {
  std::vector<std::string> req_skills{"java", "nodejs", "reactjs"};
  std::vector<std::vector<std::string>> people{
      {"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
  const auto answer = solution.smallestSufficientTeam(req_skills, people);
  EXPECT_EQ(2, answer.size());
}

TEST_P(SmallestSufficientTeamTest, PreservesOriginalIndexAfterEmptyPeople) {
  std::vector<std::string> req_skills{"a", "b", "c"};
  std::vector<std::vector<std::string>> people{
      {"a"}, {}, {}, {"b", "c"}};
  const auto answer = solution.smallestSufficientTeam(req_skills, people);
  EXPECT_EQ((std::vector<int>{0, 3}), answer);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestSufficientTeamTestSuite, SmallestSufficientTeamTest,
    ::testing::ValuesIn(SmallestSufficientTeamSolution().getStrategyNames()));

}  // namespace problem_1125
}  // namespace leetcode
