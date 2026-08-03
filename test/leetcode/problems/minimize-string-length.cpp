#include "leetcode/problems/minimize-string-length.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2716 {

class MinimizeStringLengthTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution_.setStrategy(GetParam()); }

    MinimizeStringLengthSolution solution_;
};

TEST_P(MinimizeStringLengthTest, Example1) {
    EXPECT_EQ(3, solution_.minimizedStringLength("aaabc"));
}

TEST_P(MinimizeStringLengthTest, Example2) {
    EXPECT_EQ(3, solution_.minimizedStringLength("cbbd"));
}

TEST_P(MinimizeStringLengthTest, Example3) {
    EXPECT_EQ(4, solution_.minimizedStringLength("baadccab"));
}

TEST_P(MinimizeStringLengthTest, SelfAuthoredSingleChar) {
    EXPECT_EQ(1, solution_.minimizedStringLength("a"));
}

TEST_P(MinimizeStringLengthTest, SelfAuthoredAllSame) {
    EXPECT_EQ(1, solution_.minimizedStringLength("aaaaa"));
}

TEST_P(MinimizeStringLengthTest, SelfAuthoredAlreadyDistinct) {
    EXPECT_EQ(3, solution_.minimizedStringLength("abc"));
}

INSTANTIATE_TEST_SUITE_P(
    MinimizeStringLengthTestSuite, MinimizeStringLengthTest,
    ::testing::ValuesIn(MinimizeStringLengthSolution().getStrategyNames()));

}  // namespace problem_2716
}  // namespace leetcode
