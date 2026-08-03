#include <gtest/gtest.h>

#include "leetcode/problems/time-needed-to-buy-tickets.h"

using namespace leetcode::problem_2073;

class TimeNeededToBuyTicketsTest
    : public testing::TestWithParam<std::string> {
 protected:
  TimeNeededToBuyTicketsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(TimeNeededToBuyTicketsTest, Example1) {
  std::vector<int> tickets = {2, 3, 2};
  EXPECT_EQ(solution.timeRequiredToBuy(tickets, 2), 6);
}

TEST_P(TimeNeededToBuyTicketsTest, Example2) {
  std::vector<int> tickets = {5, 1, 1, 1};
  EXPECT_EQ(solution.timeRequiredToBuy(tickets, 0), 8);
}

TEST_P(TimeNeededToBuyTicketsTest, SinglePerson) {
  std::vector<int> tickets = {5};
  EXPECT_EQ(solution.timeRequiredToBuy(tickets, 0), 5);
}

TEST_P(TimeNeededToBuyTicketsTest, KAtEnd) {
  std::vector<int> tickets = {1, 1, 3};
  EXPECT_EQ(solution.timeRequiredToBuy(tickets, 2), 5);
}

TEST_P(TimeNeededToBuyTicketsTest, AllSame) {
  std::vector<int> tickets = {4, 4, 4, 4};
  EXPECT_EQ(solution.timeRequiredToBuy(tickets, 1), 14);
}

INSTANTIATE_TEST_SUITE_P(
    TimeNeeded, TimeNeededToBuyTicketsTest,
    testing::ValuesIn(TimeNeededToBuyTicketsSolution().getStrategyNames()));
