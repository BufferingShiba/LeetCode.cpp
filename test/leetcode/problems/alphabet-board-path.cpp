#include <gtest/gtest.h>
#include "leetcode/problems/alphabet-board-path.h"
#include <string>
#include <vector>

namespace leetcode::problem_1138::test {

namespace {

// 验证路径合法：从 (0,0) 出发，所有移动都在板内，且产生的字符序列等于 target。
bool isValidPath(const std::string& path, const std::string& target) {
    int r = 0, c = 0;
    std::string got;
    for (char m : path) {
        if (m == '!') {
            got.push_back(static_cast<char>('a' + r * 5 + c));
        } else if (m == 'U') {
            --r;
        } else if (m == 'D') {
            ++r;
        } else if (m == 'L') {
            --c;
        } else if (m == 'R') {
            ++c;
        }
        // 板子范围检查
        if (r < 0 || r > 5 || c < 0 || c > 4) return false;
        if (r == 5 && c > 0) return false;
    }
    return got == target;
}

}  // namespace

class AlphabetBoardPathTest : public ::testing::TestWithParam<std::string> {
protected:
    AlphabetBoardPathSolution solution;
    void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(AlphabetBoardPathTest, Example1) {
    EXPECT_EQ(solution.alphabetBoardPath("leet"), "DDR!UURRR!!DDD!");
}

TEST_P(AlphabetBoardPathTest, Example2) {
    EXPECT_EQ(solution.alphabetBoardPath("code"), "RR!DDRR!UUL!R!");
}

TEST_P(AlphabetBoardPathTest, SelfAuthoredSingleCharZ) {
    // 从 a 到 z：必须先左(没有左移机会，c=0) 再下，实际是最小移动 DDDDD! 先到 f 再...
    // 直接验证路径有效性而非硬编码精确串。
    std::string path = solution.alphabetBoardPath("z");
    EXPECT_TRUE(isValidPath(path, "z"));
}

TEST_P(AlphabetBoardPathTest, SelfAuthoredContainsZInMiddle) {
    std::string path = solution.alphabetBoardPath("azb");
    EXPECT_TRUE(isValidPath(path, "azb"));
}

TEST_P(AlphabetBoardPathTest, SelfAuthoredSingleCharA) {
    EXPECT_EQ(solution.alphabetBoardPath("a"), "!");
}

INSTANTIATE_TEST_SUITE_P(
    AlphabetBoardPathTestCases,
    AlphabetBoardPathTest,
    ::testing::ValuesIn(AlphabetBoardPathSolution().getStrategyNames()));

}  // namespace leetcode::problem_1138::test
