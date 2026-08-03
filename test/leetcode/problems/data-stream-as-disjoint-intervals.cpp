#include <gtest/gtest.h>
#include "leetcode/problems/data-stream-as-disjoint-intervals.h"

using leetcode::problem_352::SummaryRanges;

class DataStreamAsDisjointIntervalsTest : public testing::TestWithParam<int> {
protected:
    SummaryRanges summaryRanges;
};

TEST_P(DataStreamAsDisjointIntervalsTest, Example1) {
    // Initial state: empty
    EXPECT_EQ(summaryRanges.getIntervals(), std::vector<std::vector<int>>{});

    summaryRanges.addNum(1);
    EXPECT_EQ(summaryRanges.getIntervals(),
              (std::vector<std::vector<int>>{{1, 1}}));

    summaryRanges.addNum(3);
    EXPECT_EQ(summaryRanges.getIntervals(),
              (std::vector<std::vector<int>>{{1, 1}, {3, 3}}));

    summaryRanges.addNum(7);
    EXPECT_EQ(summaryRanges.getIntervals(),
              (std::vector<std::vector<int>>{{1, 1}, {3, 3}, {7, 7}}));

    summaryRanges.addNum(2);
    EXPECT_EQ(summaryRanges.getIntervals(),
              (std::vector<std::vector<int>>{{1, 3}, {7, 7}}));

    summaryRanges.addNum(6);
    EXPECT_EQ(summaryRanges.getIntervals(),
              (std::vector<std::vector<int>>{{1, 3}, {6, 7}}));
}

TEST_P(DataStreamAsDisjointIntervalsTest, SelfAuthoredDuplicateValues) {
    summaryRanges.addNum(5);
    summaryRanges.addNum(5);
    summaryRanges.addNum(5);
    EXPECT_EQ(summaryRanges.getIntervals(),
              (std::vector<std::vector<int>>{{5, 5}}));
}

TEST_P(DataStreamAsDisjointIntervalsTest, SelfAuthoredMergeMultipleIntoOne) {
    summaryRanges.addNum(3);
    summaryRanges.addNum(1);
    summaryRanges.addNum(2);
    summaryRanges.addNum(5);
    summaryRanges.addNum(4);
    EXPECT_EQ(summaryRanges.getIntervals(),
              (std::vector<std::vector<int>>{{1, 5}}));
}

TEST_P(DataStreamAsDisjointIntervalsTest, SelfAuthoredSeparateIntervalsStaySeparate) {
    summaryRanges.addNum(10);
    summaryRanges.addNum(20);
    summaryRanges.addNum(30);
    EXPECT_EQ(summaryRanges.getIntervals(),
              (std::vector<std::vector<int>>{{10, 10}, {20, 20}, {30, 30}}));
}

INSTANTIATE_TEST_SUITE_P(All, DataStreamAsDisjointIntervalsTest, testing::Values(0));
