#include <gtest/gtest.h>

#include "leetcode/problems/minimum-deletions-to-make-array-beautiful.h"

namespace leetcode {
namespace problem_2216 {

class MinimumDeletionsToMakeArrayBeautifulTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    MinimumDeletionsToMakeArrayBeautifulSolution solution;
};

TEST_P(MinimumDeletionsToMakeArrayBeautifulTest, Example1) {
    std::vector<int> nums = {1, 1, 2, 3, 5};
    EXPECT_EQ(solution.minDeletion(nums), 1);
}

TEST_P(MinimumDeletionsToMakeArrayBeautifulTest, Example2) {
    std::vector<int> nums = {1, 1, 2, 2, 3, 3};
    EXPECT_EQ(solution.minDeletion(nums), 2);
}

TEST_P(MinimumDeletionsToMakeArrayBeautifulTest, SingleElement) {
    std::vector<int> nums = {1};
    EXPECT_EQ(solution.minDeletion(nums), 1);
}

TEST_P(MinimumDeletionsToMakeArrayBeautifulTest, AllSame) {
    std::vector<int> nums = {2, 2, 2, 2};
    EXPECT_EQ(solution.minDeletion(nums), 4);
}

TEST_P(MinimumDeletionsToMakeArrayBeautifulTest, AlreadyBeautiful) {
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.minDeletion(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDeletionsToMakeArrayBeautifulTestSuite,
    MinimumDeletionsToMakeArrayBeautifulTest,
    ::testing::ValuesIn(MinimumDeletionsToMakeArrayBeautifulSolution().getStrategyNames()));

}  // namespace problem_2216
}  // namespace leetcode
