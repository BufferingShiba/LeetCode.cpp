#include <gtest/gtest.h>

#include "leetcode/problems/direction-assignments-with-exactly-k-visible-people.h"

namespace leetcode {
namespace problem_3881 {

class DirectionAssignmentsWithExactlyKVisiblePeopleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DirectionAssignmentsWithExactlyKVisiblePeopleSolution solution;
};

TEST_P(DirectionAssignmentsWithExactlyKVisiblePeopleTest, Example1) {
  EXPECT_EQ(solution.countVisiblePeople(3, 1, 0), 2);
}

TEST_P(DirectionAssignmentsWithExactlyKVisiblePeopleTest, Example2) {
  EXPECT_EQ(solution.countVisiblePeople(3, 2, 1), 4);
}

TEST_P(DirectionAssignmentsWithExactlyKVisiblePeopleTest, Example3) {
  EXPECT_EQ(solution.countVisiblePeople(1, 0, 0), 2);
}

TEST_P(DirectionAssignmentsWithExactlyKVisiblePeopleTest, SelfAuthoredKTooLarge) {
  // n = 4 means at most n-1 = 3 people can possibly be visible.
  EXPECT_EQ(solution.countVisiblePeople(4, 1, 4), 0);
}

TEST_P(DirectionAssignmentsWithExactlyKVisiblePeopleTest, SelfAuthoredAllVisible) {
  // n = 4, pos = 0, k = 3 (all people to the right must face 'R').
  EXPECT_EQ(solution.countVisiblePeople(4, 0, 3), 2);
}

INSTANTIATE_TEST_SUITE_P(
    DirectionAssignmentsWithExactlyKVisiblePeopleTestSuite,
    DirectionAssignmentsWithExactlyKVisiblePeopleTest,
    ::testing::ValuesIn(
        DirectionAssignmentsWithExactlyKVisiblePeopleSolution()
            .getStrategyNames()));

}  // namespace problem_3881
}  // namespace leetcode
