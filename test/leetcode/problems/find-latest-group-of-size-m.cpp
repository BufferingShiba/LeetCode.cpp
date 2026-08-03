#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-latest-group-of-size-m.h"

namespace leetcode {
namespace problem_1562 {
namespace {

class FindLatestGroupOfSizeMTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    FindLatestGroupOfSizeMSolution solution;
};

TEST_P(FindLatestGroupOfSizeMTest, Example1) {
    std::vector<int> arr{3, 5, 1, 2, 4};
    EXPECT_EQ(solution.findLatestStep(arr, 1), 4);
}

TEST_P(FindLatestGroupOfSizeMTest, Example2) {
    std::vector<int> arr{3, 1, 5, 4, 2};
    EXPECT_EQ(solution.findLatestStep(arr, 2), -1);
}

TEST_P(FindLatestGroupOfSizeMTest, SingleStep) {
    std::vector<int> arr{1};
    EXPECT_EQ(solution.findLatestStep(arr, 1), 1);
}

TEST_P(FindLatestGroupOfSizeMTest, FullGroup) {
    std::vector<int> arr{1, 2, 3, 4};
    EXPECT_EQ(solution.findLatestStep(arr, 4), 4);
}

TEST_P(FindLatestGroupOfSizeMTest, NoGroupEver) {
    std::vector<int> arr{1, 3, 2};
    EXPECT_EQ(solution.findLatestStep(arr, 2), -1);
}

INSTANTIATE_TEST_SUITE_P(
    FindLatestGroupOfSizeMSolutionTests, FindLatestGroupOfSizeMTest,
    ::testing::ValuesIn(FindLatestGroupOfSizeMSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1562
}  // namespace leetcode
