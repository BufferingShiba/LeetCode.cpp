#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/string-compression-iii.h"

namespace leetcode {
namespace problem_3163 {

class StringCompressionIiiTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    StringCompressionIiiSolution solution;
};

TEST_P(StringCompressionIiiTest, Example1) {
    EXPECT_EQ(solution.compressedString("abcde"), "1a1b1c1d1e");
}

TEST_P(StringCompressionIiiTest, Example2) {
    EXPECT_EQ(solution.compressedString("aaaaaaaaaaaaaabb"), "9a5a2b");
}

TEST_P(StringCompressionIiiTest, SelfAuthoredSingleChar) {
    EXPECT_EQ(solution.compressedString("a"), "1a");
}

TEST_P(StringCompressionIiiTest, SelfAuthoredExactlyNine) {
    EXPECT_EQ(solution.compressedString("aaaaaaaaa"), "9a");
}

TEST_P(StringCompressionIiiTest, SelfAuthoredTenSameChars) {
    EXPECT_EQ(solution.compressedString("aaaaaaaaaa"), "9a1a");
}

TEST_P(StringCompressionIiiTest, SelfAuthoredDifferentCharsBoundary) {
    EXPECT_EQ(solution.compressedString("aabbcc"), "2a2b2c");
}

INSTANTIATE_TEST_SUITE_P(
    StringCompressionIiiTestSuite, StringCompressionIiiTest,
    ::testing::ValuesIn(StringCompressionIiiSolution().getStrategyNames()));

}  // namespace problem_3163
}  // namespace leetcode
