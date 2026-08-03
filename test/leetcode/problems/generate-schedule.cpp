#include <gtest/gtest.h>

#include "leetcode/problems/generate-schedule.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3680 {
namespace {

void expectValidSchedule(int n,
                         const std::vector<std::vector<int>>& schedule) {
  if (n <= 4) {
    EXPECT_TRUE(schedule.empty());
    return;
  }

  ASSERT_EQ(n * (n - 1), static_cast<int>(schedule.size()));
  std::vector<std::vector<int>> seen(n, std::vector<int>(n, 0));
  for (int day = 0; day < static_cast<int>(schedule.size()); ++day) {
    ASSERT_EQ(2U, schedule[day].size());
    const int home = schedule[day][0];
    const int away = schedule[day][1];
    ASSERT_GE(home, 0);
    ASSERT_LT(home, n);
    ASSERT_GE(away, 0);
    ASSERT_LT(away, n);
    ASSERT_NE(home, away);
    ASSERT_EQ(0, seen[home][away]);
    ++seen[home][away];

    if (day > 0) {
      const int previous_home = schedule[day - 1][0];
      const int previous_away = schedule[day - 1][1];
      EXPECT_NE(home, previous_home);
      EXPECT_NE(home, previous_away);
      EXPECT_NE(away, previous_home);
      EXPECT_NE(away, previous_away);
    }
  }

  for (int home = 0; home < n; ++home) {
    for (int away = 0; away < n; ++away) {
      if (home != away) {
        EXPECT_EQ(1, seen[home][away]);
      }
    }
  }
}

class GenerateScheduleTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GenerateScheduleSolution solution;
};

TEST_P(GenerateScheduleTest, Example1) {
  expectValidSchedule(3, solution.generateSchedule(3));
}

TEST_P(GenerateScheduleTest, Example2) {
  expectValidSchedule(5, solution.generateSchedule(5));
}

TEST_P(GenerateScheduleTest, SmallImpossibleCase) {
  expectValidSchedule(4, solution.generateSchedule(4));
}

TEST_P(GenerateScheduleTest, EvenTeams) {
  expectValidSchedule(6, solution.generateSchedule(6));
}

TEST_P(GenerateScheduleTest, MaximumTeams) {
  expectValidSchedule(50, solution.generateSchedule(50));
}

TEST_P(GenerateScheduleTest, EverySupportedTeamCount) {
  for (int n = 5; n <= 50; ++n) {
    expectValidSchedule(n, solution.generateSchedule(n));
  }
}

INSTANTIATE_TEST_SUITE_P(
    GenerateScheduleStrategies, GenerateScheduleTest,
    ::testing::ValuesIn(GenerateScheduleSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3680
}  // namespace leetcode
