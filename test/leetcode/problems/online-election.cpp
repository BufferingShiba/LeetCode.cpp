#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/online-election.h"

namespace leetcode {
namespace problem_911 {

class OnlineElectionTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(OnlineElectionTest, Example1) {
  std::vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
  std::vector<int> times = {0, 5, 10, 15, 20, 25, 30};
  TopVotedCandidate obj(persons, times);

  EXPECT_EQ(obj.q(3), 0);
  EXPECT_EQ(obj.q(12), 1);
  EXPECT_EQ(obj.q(25), 1);
  EXPECT_EQ(obj.q(15), 0);
  EXPECT_EQ(obj.q(24), 0);
  EXPECT_EQ(obj.q(8), 1);
}

INSTANTIATE_TEST_SUITE_P(/* no prefix */, OnlineElectionTest,
                         ::testing::Values(0));

}  // namespace problem_911
}  // namespace leetcode
