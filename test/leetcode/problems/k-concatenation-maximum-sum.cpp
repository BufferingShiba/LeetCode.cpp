#include <gtest/gtest.h>
#include "leetcode/problems/k-concatenation-maximum-sum.h"

#include <string>
#include <vector>

namespace leetcode::problem_1191 {

namespace {

std::vector<int> build(const std::vector<int>& a, int times) {
    std::vector<int> out;
    out.reserve(a.size() * times);
    for (int t = 0; t < times; ++t) {
        out.insert(out.end(), a.begin(), a.end());
    }
    return out;
}

long long bruteForce(const std::vector<int>& arr, int k) {
    std::vector<int> full = build(arr, k);
    long long best = 0;
    for (size_t i = 0; i < full.size(); ++i) {
        long long s = 0;
        for (size_t j = i; j < full.size(); ++j) {
            s += full[j];
            best = std::max(best, s);
        }
    }
    return best % 1000000007LL;
}

}  // namespace

class KConcatenationMaximumSumTest : public ::testing::TestWithParam<std::string> {
protected:
    KConcatenationMaximumSumSolution solution;

    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(KConcatenationMaximumSumTest, Example1) {
    std::vector<int> arr{1, 2};
    EXPECT_EQ(9, solution.kConcatenationMaxSum(arr, 3));
}

TEST_P(KConcatenationMaximumSumTest, Example2) {
    std::vector<int> arr{1, -2, 1};
    EXPECT_EQ(2, solution.kConcatenationMaxSum(arr, 5));
}

TEST_P(KConcatenationMaximumSumTest, Example3) {
    std::vector<int> arr{-1, -2};
    EXPECT_EQ(0, solution.kConcatenationMaxSum(arr, 7));
}

TEST_P(KConcatenationMaximumSumTest, KEqualTo1) {
    std::vector<int> arr{5, -3, 9};
    EXPECT_EQ(11, solution.kConcatenationMaxSum(arr, 1));
}

TEST_P(KConcatenationMaximumSumTest, SingleElementLargeK) {
    std::vector<int> arr{5};
    EXPECT_EQ(15, solution.kConcatenationMaxSum(arr, 3));
}

TEST_P(KConcatenationMaximumSumTest, AllNegative) {
    std::vector<int> arr{-3, -5};
    EXPECT_EQ(0, solution.kConcatenationMaxSum(arr, 4));
}

TEST_P(KConcatenationMaximumSumTest, SelfAuthoredCrossBoundary) {
    // arr: [2,-5,3,2,-5,3,2,-5,3] -> 最大子数组 3+2=5
    std::vector<int> arr{2, -5, 3};
    EXPECT_EQ(5, solution.kConcatenationMaxSum(arr, 3));
}

TEST_P(KConcatenationMaximumSumTest, PositiveTotalRepeat) {
    // total>0 时中间可填满完整副本，暴力验证
    std::vector<int> arr{1, 2, -1};
    const int k = 4;
    EXPECT_EQ(static_cast<int>(bruteForce(arr, k)),
              solution.kConcatenationMaxSum(arr, k));
}

TEST_P(KConcatenationMaximumSumTest, LargeValuesModulo) {
    // 每副本和为 10^4，k=10^5，n=1 -> 巨大数值需取模
    std::vector<int> arr{10000};
    long long total = 10000LL * 100000LL;  // 1e9
    EXPECT_EQ(static_cast<int>(total % 1000000007LL),
              solution.kConcatenationMaxSum(arr, 100000));
}

TEST_P(KConcatenationMaximumSumTest, RandomSmallBruteCheck) {
    std::vector<int> arr{3, -1, 2, -4, 5, -2, 1, -1, 4, -3};
    const int k = 4;
    EXPECT_EQ(static_cast<int>(bruteForce(arr, k)),
              solution.kConcatenationMaxSum(arr, k));
}

INSTANTIATE_TEST_SUITE_P(
    KConcatenationMaximumSumStrategies,
    KConcatenationMaximumSumTest,
    ::testing::ValuesIn(KConcatenationMaximumSumSolution().getStrategyNames()));

}  // namespace leetcode::problem_1191
