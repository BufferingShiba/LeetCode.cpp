#include <gtest/gtest.h>

#include "leetcode/problems/first-day-where-you-have-been-in-all-the-rooms.h"

using namespace leetcode::problem_1997;

class FirstDayWhereYouHaveBeenInAllTheRoomsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  FirstDayWhereYouHaveBeenInAllTheRoomsSolution solution;
};

TEST_P(FirstDayWhereYouHaveBeenInAllTheRoomsTest, Example1) {
  std::vector<int> nextVisit = {0, 0};
  EXPECT_EQ(solution.firstDayBeenInAllRooms(nextVisit), 2);
}

TEST_P(FirstDayWhereYouHaveBeenInAllTheRoomsTest, Example2) {
  std::vector<int> nextVisit = {0, 0, 2};
  EXPECT_EQ(solution.firstDayBeenInAllRooms(nextVisit), 6);
}

TEST_P(FirstDayWhereYouHaveBeenInAllTheRoomsTest, Example3) {
  std::vector<int> nextVisit = {0, 1, 2, 0};
  EXPECT_EQ(solution.firstDayBeenInAllRooms(nextVisit), 6);
}

TEST_P(FirstDayWhereYouHaveBeenInAllTheRoomsTest, SelfAuthored_AllZero) {
  std::vector<int> nextVisit = {0, 0, 0, 0};
  EXPECT_EQ(solution.firstDayBeenInAllRooms(nextVisit), 14);
}

TEST_P(FirstDayWhereYouHaveBeenInAllTheRoomsTest, SelfAuthored_SelfLoop) {
  std::vector<int> nextVisit = {0, 1};
  EXPECT_EQ(solution.firstDayBeenInAllRooms(nextVisit), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FirstDayWhereYouHaveBeenInAllTheRoomsTest,
    testing::ValuesIn(
        FirstDayWhereYouHaveBeenInAllTheRoomsSolution().getStrategyNames()));
