#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/pizza-with-3n-slices.h"

namespace leetcode {
namespace problem_1388 {

class PizzaWith3nSlicesTest
    : public testing::TestWithParam<std::string> {
 protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    PizzaWith3nSlicesSolution solution_;
};

TEST_P(PizzaWith3nSlicesTest, Example1) {
    std::vector<int> slices = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(solution_.maxSizeSlices(slices), 10);
}

TEST_P(PizzaWith3nSlicesTest, Example2) {
    std::vector<int> slices = {8, 9, 8, 6, 1, 1};
    EXPECT_EQ(solution_.maxSizeSlices(slices), 16);
}

TEST_P(PizzaWith3nSlicesTest, SelfAuthoredSingleSlice) {
    // 3n = 3, n = 1, just pick the max
    std::vector<int> slices = {5, 1, 3};
    EXPECT_EQ(solution_.maxSizeSlices(slices), 5);
}

TEST_P(PizzaWith3nSlicesTest, SelfAuthoredAllEqual) {
    std::vector<int> slices = {2, 2, 2, 2, 2, 2};
    EXPECT_EQ(solution_.maxSizeSlices(slices), 4);  // n=2, pick 2 slices
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    PizzaWith3nSlicesTest,
    testing::ValuesIn(PizzaWith3nSlicesSolution().getStrategyNames()));

}  // namespace problem_1388
}  // namespace leetcode
