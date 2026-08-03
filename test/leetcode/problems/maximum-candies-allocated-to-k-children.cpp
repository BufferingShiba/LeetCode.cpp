#include <gtest/gtest.h>

#include "leetcode/problems/maximum-candies-allocated-to-k-children.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_2226 {

class MaximumCandiesAllocatedToKChildrenTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    MaximumCandiesAllocatedToKChildrenSolution solution;
};

TEST_P(MaximumCandiesAllocatedToKChildrenTest, Example1) {
    std::vector<int> candies{5, 8, 6};
    long long k = 3;
    EXPECT_EQ(solution.maximumCandies(candies, k), 5);
}

TEST_P(MaximumCandiesAllocatedToKChildrenTest, Example2) {
    std::vector<int> candies{2, 5};
    long long k = 11;
    EXPECT_EQ(solution.maximumCandies(candies, k), 0);
}

TEST_P(MaximumCandiesAllocatedToKChildrenTest, SelfAuthoredSinglePileSingleChild) {
    std::vector<int> candies{7};
    long long k = 1;
    EXPECT_EQ(solution.maximumCandies(candies, k), 7);
}

TEST_P(MaximumCandiesAllocatedToKChildrenTest, SelfAuthoredLargeKNoAllocation) {
    std::vector<int> candies{3, 3};
    long long k = 7;
    EXPECT_EQ(solution.maximumCandies(candies, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumCandiesAllocatedToKChildrenTestSuite, MaximumCandiesAllocatedToKChildrenTest,
    ::testing::ValuesIn(MaximumCandiesAllocatedToKChildrenSolution().getStrategyNames()));

}  // namespace leetcode::problem_2226
