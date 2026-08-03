#include "leetcode/problems/unique-3-digit-even-numbers.h"

#include <gtest/gtest.h>
#include <string>

namespace leetcode::problem_3483 {

class Unique3DigitEvenNumbersTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }

    Unique3DigitEvenNumbersSolution solution;
};

TEST_P(Unique3DigitEvenNumbersTest, Example1) {
    std::vector<int> digits{1, 2, 3, 4};
    EXPECT_EQ(solution.totalNumbers(digits), 12);
}

TEST_P(Unique3DigitEvenNumbersTest, Example2) {
    std::vector<int> digits{0, 2, 2};
    EXPECT_EQ(solution.totalNumbers(digits), 2);
}

TEST_P(Unique3DigitEvenNumbersTest, Example3) {
    std::vector<int> digits{6, 6, 6};
    EXPECT_EQ(solution.totalNumbers(digits), 1);
}

TEST_P(Unique3DigitEvenNumbersTest, Example4) {
    std::vector<int> digits{1, 3, 5};
    EXPECT_EQ(solution.totalNumbers(digits), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Unique3DigitEvenNumbersTestSuite, Unique3DigitEvenNumbersTest,
    ::testing::ValuesIn(Unique3DigitEvenNumbersSolution().getStrategyNames()));

}  // namespace leetcode::problem_3483
