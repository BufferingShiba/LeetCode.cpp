#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/determine-if-two-events-have-conflict.h"

namespace leetcode {
namespace problem_2446 {

class DetermineIfTwoEventsHaveConflictTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DetermineIfTwoEventsHaveConflictSolution solution;
};

TEST_P(DetermineIfTwoEventsHaveConflictTest, Example1) {
  std::vector<std::string> event1 = {"01:15", "02:00"};
  std::vector<std::string> event2 = {"02:00", "03:00"};
  EXPECT_TRUE(solution.haveConflict(event1, event2));
}

TEST_P(DetermineIfTwoEventsHaveConflictTest, Example2) {
  std::vector<std::string> event1 = {"01:00", "02:00"};
  std::vector<std::string> event2 = {"01:20", "03:00"};
  EXPECT_TRUE(solution.haveConflict(event1, event2));
}

TEST_P(DetermineIfTwoEventsHaveConflictTest, Example3) {
  std::vector<std::string> event1 = {"10:00", "11:00"};
  std::vector<std::string> event2 = {"14:00", "15:00"};
  EXPECT_FALSE(solution.haveConflict(event1, event2));
}

TEST_P(DetermineIfTwoEventsHaveConflictTest, SelfAuthoredReverseOrderNoConflict) {
  std::vector<std::string> event1 = {"02:00", "03:00"};
  std::vector<std::string> event2 = {"01:00", "01:59"};
  EXPECT_FALSE(solution.haveConflict(event1, event2));
}

TEST_P(DetermineIfTwoEventsHaveConflictTest, SelfAuthoredOneContainsOther) {
  std::vector<std::string> event1 = {"01:00", "05:00"};
  std::vector<std::string> event2 = {"02:00", "03:00"};
  EXPECT_TRUE(solution.haveConflict(event1, event2));
}

INSTANTIATE_TEST_SUITE_P(
    DetermineIfTwoEventsHaveConflictTestSuite,
    DetermineIfTwoEventsHaveConflictTest,
    ::testing::ValuesIn(DetermineIfTwoEventsHaveConflictSolution().getStrategyNames()));

}  // namespace problem_2446
}  // namespace leetcode
