#include <gtest/gtest.h>
#include <array>
#include <string>
#include <vector>

#include "leetcode/problems/lexicographically-smallest-string-after-deleting-duplicate-characters.h"

namespace leetcode::problem_3816 {

class LexSmallestAfterDeletionTest : public ::testing::TestWithParam<std::string> {
protected:
    LexSmallestAfterDeletionSolution solution;
    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

std::string bruteForce(std::string const& s) {
    std::array<bool, 26> required{};
    for (char character : s) required[character - 'a'] = true;

    std::string best;
    const int combinations = 1 << static_cast<int>(s.size());
    for (int choice = 1; choice < combinations; ++choice) {
        std::string candidate;
        std::array<bool, 26> present{};
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if ((choice & (1 << i)) == 0) continue;
            candidate.push_back(s[i]);
            present[s[i] - 'a'] = true;
        }

        bool contains_all = true;
        for (int i = 0; i < 26; ++i) {
            if (required[i] && !present[i]) {
                contains_all = false;
                break;
            }
        }
        if (contains_all && (best.empty() || candidate < best)) best = candidate;
    }
    return best;
}

TEST_P(LexSmallestAfterDeletionTest, Example1) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("aaccb"), "aacb");
}

TEST_P(LexSmallestAfterDeletionTest, Example2) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("z"), "z");
}

TEST_P(LexSmallestAfterDeletionTest, TrailingDuplicate) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("aba"), "ab");
}

TEST_P(LexSmallestAfterDeletionTest, LeadingLarge) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("baab"), "aab");
}

TEST_P(LexSmallestAfterDeletionTest, AllThreeDup) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("abcabc"), "aabc");
}

TEST_P(LexSmallestAfterDeletionTest, MiddleDup) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("abbca"), "abbc");
}

TEST_P(LexSmallestAfterDeletionTest, TrailingDupAfterPop) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("aabccb"), "aabc");
}

TEST_P(LexSmallestAfterDeletionTest, SingleChar) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("a"), "a");
}

TEST_P(LexSmallestAfterDeletionTest, OnlineCounterExample) {
    EXPECT_EQ(solution.lexSmallestAfterDeletion("aaa"), "a");
}

TEST_P(LexSmallestAfterDeletionTest, ExhaustiveSmallStrings) {
    for (int length = 1; length <= 6; ++length) {
        const int combinations = [&] {
            int value = 1;
            for (int i = 0; i < length; ++i) value *= 3;
            return value;
        }();
        for (int code = 0; code < combinations; ++code) {
            int value = code;
            std::string input(length, 'a');
            for (char& character : input) {
                character = static_cast<char>('a' + value % 3);
                value /= 3;
            }
            EXPECT_EQ(solution.lexSmallestAfterDeletion(input), bruteForce(input))
                << "input=" << input;
        }
    }
}

INSTANTIATE_TEST_SUITE_P(LexSmallestAfterDeletionTestCases, LexSmallestAfterDeletionTest,
                         ::testing::ValuesIn(LexSmallestAfterDeletionSolution().getStrategyNames()));

}  // namespace leetcode::problem_3816
