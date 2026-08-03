#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-cost-for-tickets.h"

namespace leetcode {
namespace problem_983 {

class MinimumCostForTicketsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumCostForTicketsSolution solution_;
};

TEST_P(MinimumCostForTicketsTest, Example1) {
  std::vector<int> days = {1, 4, 6, 7, 8, 20};
  std::vector<int> costs = {2, 7, 15};
  EXPECT_EQ(11, solution_.mincostTickets(days, costs));
}

TEST_P(MinimumCostForTicketsTest, Example2) {
  std::vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  std::vector<int> costs = {2, 7, 15};
  EXPECT_EQ(17, solution_.mincostTickets(days, costs));
}

TEST_P(MinimumCostForTicketsTest, SelfAuthoredSingleDayCheapestPassIsDaily) {
  std::vector<int> days = {1};
  std::vector<int> costs = {2, 100, 100};
  EXPECT_EQ(2, solution_.mincostTickets(days, costs));
}

TEST_P(MinimumCostForTicketsTest, SelfAuthoredSevenDayPassBeatsDaily) {
  std::vector<int> days = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> costs = {2, 7, 15};
  EXPECT_EQ(7, solution_.mincostTickets(days, costs));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostForTicketsTestSuite, MinimumCostForTicketsTest,
    ::testing::ValuesIn(MinimumCostForTicketsSolution().getStrategyNames()));

}  // namespace problem_983
}  // namespace leetcode
