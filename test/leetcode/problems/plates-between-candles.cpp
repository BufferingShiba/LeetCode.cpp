#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/plates-between-candles.h"

namespace leetcode::problem_2055 {

class PlatesBetweenCandlesTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    PlatesBetweenCandlesSolution solution_;
};

TEST_P(PlatesBetweenCandlesTest, Example1) {
    std::string s = "**|**|***|";
    std::vector<std::vector<int>> queries = {{2, 5}, {5, 9}};
    std::vector<int> expected = {2, 3};
    EXPECT_EQ(expected, solution_.platesBetweenCandles(s, queries));
}

TEST_P(PlatesBetweenCandlesTest, Example2) {
    std::string s = "***|**|*****|**||**|*";
    std::vector<std::vector<int>> queries = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
    std::vector<int> expected = {9, 0, 0, 0, 0};
    EXPECT_EQ(expected, solution_.platesBetweenCandles(s, queries));
}

TEST_P(PlatesBetweenCandlesTest, WholeStringWithCandles) {
    std::string s = "|**|**|";
    std::vector<std::vector<int>> queries = {{0, 6}};
    std::vector<int> expected = {4};
    EXPECT_EQ(expected, solution_.platesBetweenCandles(s, queries));
}

TEST_P(PlatesBetweenCandlesTest, SinglePlateBetweenCandles) {
    std::string s = "**|*|**";
    std::vector<std::vector<int>> queries = {{1, 4}};
    // [1,4] => "*|*|" => L=2, R=4 => plates between = prefix[5]-prefix[2]=3-2=1
    std::vector<int> expected = {1};
    EXPECT_EQ(expected, solution_.platesBetweenCandles(s, queries));
}

TEST_P(PlatesBetweenCandlesTest, NoCandlesEnclose) {
    std::string s = "**|*|**";
    std::vector<std::vector<int>> queries = {{0, 3}};
    // [0,3] => "**|*" => L=2, R=2 => 不满足 L<R => 0
    std::vector<int> expected = {0};
    EXPECT_EQ(expected, solution_.platesBetweenCandles(s, queries));
}

TEST_P(PlatesBetweenCandlesTest, EmptyRangeNoCandles) {
    std::string s = "*****";
    std::vector<std::vector<int>> queries = {{0, 4}};
    std::vector<int> expected = {0};
    EXPECT_EQ(expected, solution_.platesBetweenCandles(s, queries));
}

INSTANTIATE_TEST_SUITE_P(
    PlatesBetweenCandlesTestParam,
    PlatesBetweenCandlesTest,
    ::testing::ValuesIn(PlatesBetweenCandlesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2055
