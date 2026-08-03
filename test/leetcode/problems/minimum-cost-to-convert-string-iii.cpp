#include <gtest/gtest.h>

#include "leetcode/problems/minimum-cost-to-convert-string-iii.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3995 {

class MinimumCostToConvertStringIiiTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    MinimumCostToConvertStringIiiSolution solution;
};

TEST_P(MinimumCostToConvertStringIiiTest, Example1) {
    std::string source = "hello";
    std::string target = "world";
    std::vector<std::vector<std::string>> rules = {{"he", "wo"}, {"llo", "rld"}};
    std::vector<int> costs = {3, 4};
    EXPECT_EQ(7, solution.minCost(source, target, rules, costs));
}

TEST_P(MinimumCostToConvertStringIiiTest, Example2) {
    std::string source = "cat";
    std::string target = "dog";
    std::vector<std::vector<std::string>> rules = {{"c*t", "dog"}};
    std::vector<int> costs = {2};
    EXPECT_EQ(3, solution.minCost(source, target, rules, costs));
}

TEST_P(MinimumCostToConvertStringIiiTest, Example3) {
    std::string source = "test";
    std::string target = "next";
    std::vector<std::vector<std::string>> rules = {{"*e*t", "next"}};
    std::vector<int> costs = {4};
    EXPECT_EQ(6, solution.minCost(source, target, rules, costs));
}

TEST_P(MinimumCostToConvertStringIiiTest, Example4) {
    std::string source = "ab";
    std::string target = "bc";
    std::vector<std::vector<std::string>> rules = {{"a*", "bd"}};
    std::vector<int> costs = {9};
    EXPECT_EQ(-1, solution.minCost(source, target, rules, costs));
}

TEST_P(MinimumCostToConvertStringIiiTest, SelfAuthoredAlreadyEqual) {
    std::string source = "abc";
    std::string target = "abc";
    std::vector<std::vector<std::string>> rules = {{"*", "z"}};
    std::vector<int> costs = {5};
    EXPECT_EQ(0, solution.minCost(source, target, rules, costs));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToConvertStringIiiTestSuite,
    MinimumCostToConvertStringIiiTest,
    ::testing::ValuesIn(MinimumCostToConvertStringIiiSolution().getStrategyNames()));

}  // namespace problem_3995
}  // namespace leetcode
