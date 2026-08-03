#include <gtest/gtest.h>

#include "leetcode/problems/happy-students.h"

namespace leetcode {
namespace problem_2860 {

class HappyStudentsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  HappyStudentsSolution solution;
};

TEST_P(HappyStudentsTest, Example1) {
  std::vector<int> nums = {1, 1};
  EXPECT_EQ(solution.countWays(nums), 2);
}

TEST_P(HappyStudentsTest, Example2) {
  std::vector<int> nums = {6, 0, 3, 3, 6, 7, 2, 7};
  EXPECT_EQ(solution.countWays(nums), 3);
}

TEST_P(HappyStudentsTest, SelfAuthoredSingleStudent) {
  std::vector<int> nums = {0};
  // n=1: k=0 -> cnt(<0)=0, k==0, exists==0? yes(0) -> no.
  //      k=1 -> cnt(<1)=1, k==1, exists==1? no -> valid. ans=1
  EXPECT_EQ(solution.countWays(nums), 1);
}

TEST_P(HappyStudentsTest, SelfAuthoredAllZero) {
  std::vector<int> nums = {0, 0, 0};
  // n=3. For k where exists==k excluded.
  EXPECT_EQ(solution.countWays(nums), 1);  // k=3: cnt(<3)=3, exists==3? no -> valid.
}

INSTANTIATE_TEST_SUITE_P(
    HappyStudentsTestSuite, HappyStudentsTest,
    ::testing::ValuesIn(HappyStudentsSolution().getStrategyNames()));

}  // namespace problem_2860
}  // namespace leetcode
