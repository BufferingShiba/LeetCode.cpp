#include <gtest/gtest.h>

#include "leetcode/problems/x-of-a-kind-in-a-deck-of-cards.h"

namespace leetcode::problem_914 {

class XOfAKindInADeckOfCardsTest
    : public ::testing::TestWithParam<std::string> {
protected:
    XOfAKindInADeckOfCardsSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(XOfAKindInADeckOfCardsTest, Example1) {
    std::vector<int> deck{1, 2, 3, 4, 4, 3, 2, 1};
    EXPECT_TRUE(solution.hasGroupsSizeX(deck));
}

TEST_P(XOfAKindInADeckOfCardsTest, Example2) {
    std::vector<int> deck{1, 1, 1, 2, 2, 2, 3, 3};
    EXPECT_FALSE(solution.hasGroupsSizeX(deck));
}

TEST_P(XOfAKindInADeckOfCardsTest, SelfAuthoredSingleElement) {
    std::vector<int> deck{1};
    EXPECT_FALSE(solution.hasGroupsSizeX(deck));
}

TEST_P(XOfAKindInADeckOfCardsTest, SelfAuthoredAllSameCards) {
    std::vector<int> deck{1, 1, 1, 1, 1, 1};
    EXPECT_TRUE(solution.hasGroupsSizeX(deck));
}

TEST_P(XOfAKindInADeckOfCardsTest, SelfAuthoredTwoGroupsOfTwo) {
    std::vector<int> deck{0, 0, 1, 1};
    EXPECT_TRUE(solution.hasGroupsSizeX(deck));
}

INSTANTIATE_TEST_SUITE_P(
    XOfAKindInADeckOfCardsTestParams, XOfAKindInADeckOfCardsTest,
    ::testing::ValuesIn(
        XOfAKindInADeckOfCardsSolution().getStrategyNames()));

}  // namespace leetcode::problem_914
