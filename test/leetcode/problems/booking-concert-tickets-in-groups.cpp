#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/booking-concert-tickets-in-groups.h"

namespace leetcode {
namespace problem_2286 {

class BookingConcertTicketsInGroupsTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(BookingConcertTicketsInGroupsTest, OfficialExample1) {
  BookMyShow bms(2, 5);
  EXPECT_EQ(bms.gather(4, 0), (std::vector<int>{0, 0}));
  EXPECT_TRUE(bms.gather(2, 0).empty());
  EXPECT_TRUE(bms.scatter(5, 1));
  EXPECT_FALSE(bms.scatter(5, 1));
}

TEST_P(BookingConcertTicketsInGroupsTest, GatherPicksSmallestRow) {
  BookMyShow bms(2, 5);
  EXPECT_EQ(bms.gather(4, 0), (std::vector<int>{0, 0}));
  EXPECT_EQ(bms.gather(5, 1), (std::vector<int>{1, 0}));
  EXPECT_TRUE(bms.gather(5, 1).empty());
  EXPECT_EQ(bms.gather(1, 1), (std::vector<int>{0, 4}));
}

TEST_P(BookingConcertTicketsInGroupsTest, GatherScatterInterplay) {
  BookMyShow bms(3, 4);
  EXPECT_EQ(bms.gather(3, 1), (std::vector<int>{0, 0}));
  EXPECT_TRUE(bms.scatter(2, 1));
  EXPECT_EQ(bms.gather(3, 1), (std::vector<int>{1, 1}));
}

TEST_P(BookingConcertTicketsInGroupsTest, ScatterFillsLeftmostRows) {
  BookMyShow bms(2, 3);
  EXPECT_TRUE(bms.scatter(4, 1));
  EXPECT_EQ(bms.gather(2, 1), (std::vector<int>{1, 1}));
  // row1 is now full, so no seats remain in rows 0..1
  EXPECT_FALSE(bms.scatter(1, 1));
  EXPECT_TRUE(bms.gather(5, 1).empty());
}

INSTANTIATE_TEST_SUITE_P(
    BookingConcertTicketsInGroupsTestParameters, BookingConcertTicketsInGroupsTest,
    ::testing::Values(0));

}  // namespace problem_2286
}  // namespace leetcode
