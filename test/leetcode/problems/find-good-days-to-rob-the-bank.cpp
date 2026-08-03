#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/find-good-days-to-rob-the-bank.h"

namespace leetcode {
namespace problem_2100 {

class FindGoodDaysToRobTheBankTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindGoodDaysToRobTheBankSolution solution_;
};

TEST_P(FindGoodDaysToRobTheBankTest, OfficialExample1) {
  std::vector<int> security = {5, 3, 3, 3, 5, 6, 2};
  int time = 2;
  auto result = solution_.goodDaysToRobBank(security, time);
  std::vector<int> expected = {2, 3};
  EXPECT_EQ(result, expected);
}

TEST_P(FindGoodDaysToRobTheBankTest, OfficialExample2) {
  std::vector<int> security = {1, 1, 1, 1, 1};
  int time = 0;
  auto result = solution_.goodDaysToRobBank(security, time);
  std::vector<int> expected = {0, 1, 2, 3, 4};
  EXPECT_EQ(result, expected);
}

TEST_P(FindGoodDaysToRobTheBankTest, OfficialExample3) {
  std::vector<int> security = {1, 2, 3, 4, 5, 6};
  int time = 2;
  auto result = solution_.goodDaysToRobBank(security, time);
  std::vector<int> expected = {};
  EXPECT_EQ(result, expected);
}

TEST_P(FindGoodDaysToRobTheBankTest, SelfAuthoredTimeZero) {
  std::vector<int> security = {3, 1, 4, 1, 5};
  int time = 0;
  auto result = solution_.goodDaysToRobBank(security, time);
  std::vector<int> expected = {0, 1, 2, 3, 4};
  EXPECT_EQ(result, expected);
}

TEST_P(FindGoodDaysToRobTheBankTest, SelfAuthoredTimeEqualsHalf) {
  // security = [5,4,3,2,1,2,3,4,5], time = 2
  // 只有 i=4 (值=1) 满足：左边 5>=4>=3>=2>=1 (4步非递增), 右边 1<=2<=3<=4<=5 (4步非递减)
  std::vector<int> security = {5, 4, 3, 2, 1, 2, 3, 4, 5};
  int time = 2;
  auto result = solution_.goodDaysToRobBank(security, time);
  std::vector<int> expected = {4};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindGoodDaysToRobTheBankTest,
    testing::ValuesIn(
        FindGoodDaysToRobTheBankSolution().getStrategyNames()));

}  // namespace problem_2100
}  // namespace leetcode
