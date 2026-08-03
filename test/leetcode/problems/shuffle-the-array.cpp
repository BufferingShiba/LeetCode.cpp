#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/shuffle-the-array.h"

namespace leetcode::problem_1470 {

class ShuffleTheArrayTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    ShuffleTheArraySolution solution_;
};

TEST_P(ShuffleTheArrayTest, Example1) {
    std::vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;
    std::vector<int> expected = {2, 3, 5, 4, 1, 7};
    EXPECT_EQ(solution_.shuffle(nums, n), expected);
}

TEST_P(ShuffleTheArrayTest, Example2) {
    std::vector<int> nums = {1, 2, 3, 4, 4, 3, 2, 1};
    int n = 4;
    std::vector<int> expected = {1, 4, 2, 3, 3, 2, 4, 1};
    EXPECT_EQ(solution_.shuffle(nums, n), expected);
}

TEST_P(ShuffleTheArrayTest, Example3) {
    std::vector<int> nums = {1, 1, 2, 2};
    int n = 2;
    std::vector<int> expected = {1, 2, 1, 2};
    EXPECT_EQ(solution_.shuffle(nums, n), expected);
}

TEST_P(ShuffleTheArrayTest, SelfAuthoredSinglePair) {
    std::vector<int> nums = {5, 9};
    int n = 1;
    std::vector<int> expected = {5, 9};
    EXPECT_EQ(solution_.shuffle(nums, n), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ShuffleTheArrayTestSuite,
    ShuffleTheArrayTest,
    ::testing::ValuesIn(ShuffleTheArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_1470
