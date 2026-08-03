#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/remove-all-adjacent-duplicates-in-string-ii.h"

namespace leetcode {
namespace problem_1209 {

using leetcode::problem_1209::RemoveAllAdjacentDuplicatesInStringIiSolution;

namespace {

std::string extractArg(std::string&& s) {
    return s;
}

}  // namespace

class RemoveAllAdjacentDuplicatesInStringIiTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    RemoveAllAdjacentDuplicatesInStringIiSolution solution_;
};

TEST_P(RemoveAllAdjacentDuplicatesInStringIiTest, Example1) {
    std::string s = "abcd";
    int k = 2;
    EXPECT_EQ("abcd", solution_.removeDuplicates(extractArg(std::move(s)), k));
}

TEST_P(RemoveAllAdjacentDuplicatesInStringIiTest, Example2) {
    std::string s = "deeedbbcccbdaa";
    int k = 3;
    EXPECT_EQ("aa", solution_.removeDuplicates(extractArg(std::move(s)), k));
}

TEST_P(RemoveAllAdjacentDuplicatesInStringIiTest, Example3) {
    std::string s = "pbbcggttciiippooaais";
    int k = 2;
    EXPECT_EQ("ps", solution_.removeDuplicates(extractArg(std::move(s)), k));
}

TEST_P(RemoveAllAdjacentDuplicatesInStringIiTest, SelfAuthoredSingleCharNoRemoval) {
    std::string s = "a";
    int k = 2;
    EXPECT_EQ("a", solution_.removeDuplicates(extractArg(std::move(s)), k));
}

TEST_P(RemoveAllAdjacentDuplicatesInStringIiTest, SelfAuthoredAllRemoved) {
    std::string s = "aa";
    int k = 2;
    EXPECT_EQ("", solution_.removeDuplicates(extractArg(std::move(s)), k));
}

TEST_P(RemoveAllAdjacentDuplicatesInStringIiTest, SelfAuthoredCrossBoundaryRemoval) {
    std::string s = "aabbcc";
    int k = 2;
    EXPECT_EQ("", solution_.removeDuplicates(extractArg(std::move(s)), k));
}

INSTANTIATE_TEST_SUITE_P(
    RemoveAllAdjacentDuplicatesInStringIiTestSuite,
    RemoveAllAdjacentDuplicatesInStringIiTest,
    ::testing::ValuesIn(
        RemoveAllAdjacentDuplicatesInStringIiSolution().getStrategyNames()));

}  // namespace problem_1209
}  // namespace leetcode
