#include "leetcode/problems/k-concatenation-maximum-sum.h"

#include <algorithm>

namespace leetcode::problem_1191 {

namespace {

constexpr long long kMod = 1000000007LL;

// 单数组内最大子数组和（Kadane，允许为空则为0）。
long long maxSubArraySum(const std::vector<int>& arr) {
    long long cur = 0;
    long long best = 0;
    for (int x : arr) {
        cur = std::max(0LL, cur + x);
        best = std::max(best, cur);
    }
    return best;
}

int kConcatenationMaxSumImpl(std::vector<int>& arr, int k) {
    long long single = maxSubArraySum(arr);
    if (k == 1) {
        return static_cast<int>(single % kMod);
    }

    long long total = 0;
    long long prefix = 0;
    long long suffix = 0;
    long long run = 0;

    for (int x : arr) total += x;

    // 最大前缀和
    run = 0;
    for (int x : arr) {
        run += x;
        prefix = std::max(prefix, run);
    }

    // 最大后缀和（从末尾向前累加）
    long long suffixRun = 0;
    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
        suffixRun += arr[i];
        suffix = std::max(suffix, suffixRun);
    }

    // 跨越 k 个副本的最大子数组 = 前缀 + 后缀 + (k-2) 个中间完整副本（若 total>0）
    long long cross = prefix + suffix + (k - 2LL) * std::max(0LL, total);
    cross = std::max(0LL, cross);

    long long ans = std::max(single, cross) % kMod;
    return static_cast<int>(ans);
}

}  // namespace

KConcatenationMaximumSumSolution::KConcatenationMaximumSumSolution() {
    setMetaInfo({.id = 1191,
                 .title = "K-Concatenation Maximum Sum",
                 .url = "https://leetcode.com/problems/k-concatenation-maximum-sum/"});

    registerStrategy(
        {.name = "kadane-cross-boundary",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Dynamic Programming"}},
        kConcatenationMaxSumImpl);
}

int KConcatenationMaximumSumSolution::kConcatenationMaxSum(std::vector<int>& arr, int k) {
    return getSolution()(arr, k);
}

}  // namespace leetcode::problem_1191
