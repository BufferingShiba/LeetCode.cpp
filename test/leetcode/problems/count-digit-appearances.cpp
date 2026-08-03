#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "leetcode/problems/count-digit-appearances.h"

namespace leetcode::problem_3895 {

class CountDigitAppearancesTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    CountDigitAppearancesSolution solution_;
};

TEST_P(CountDigitAppearancesTest, Example1) {
    std::vector<int> nums{12, 54, 32, 22};
    EXPECT_EQ(solution_.countDigitOccurrences(nums, 2), 4);
}

TEST_P(CountDigitAppearancesTest, Example2) {
    std::vector<int> nums{1, 34, 7};
    EXPECT_EQ(solution_.countDigitOccurrences(nums, 9), 0);
}

TEST_P(CountDigitAppearancesTest, SingleNumberMultipleOccurrences) {
    std::vector<int> nums{1000000};
    EXPECT_EQ(solution_.countDigitOccurrences(nums, 0), 6);
}

TEST_P(CountDigitAppearancesTest, AllSameDigit) {
    std::vector<int> nums{555, 500, 5};
    EXPECT_EQ(solution_.countDigitOccurrences(nums, 5), 5);
}

INSTANTIATE_TEST_SUITE_P(
    CountDigitAppearancesTestSuite,
    CountDigitAppearancesTest,
    ::testing::ValuesIn(CountDigitAppearancesSolution().getStrategyNames()));

}  // namespace leetcode::problem_3895
