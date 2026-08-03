#include "leetcode/problems/plates-between-candles.h"

#include <string>
#include <vector>

namespace leetcode::problem_2055 {

// 策略：前缀和 + 左右最近蜡烛预处理
// 对每个查询 [l, r]：
//   L = 位置 l 右边最近的蜡烛索引
//   R = 位置 r 左边最近的蜡烛索引
//   若 L < R，则区间 [L, R] 内的盘子数即为答案（这些盘子左右都有蜡烛夹着）
static std::vector<int> platesBetweenCandlesImpl(std::string s,
                                                  std::vector<std::vector<int>>& queries) {
    const int n = static_cast<int>(s.size());

    // prefix[i] = s 前 i 个字符（[0, i-1]）中盘子的数量
    std::vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + (s[i] == '*' ? 1 : 0);
    }

    // leftCandle[i] = 位置 i（含）左边（含）最近的蜡烛索引，若无则 -1
    std::vector<int> leftCandle(n, -1);
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '|') last = i;
        leftCandle[i] = last;
    }

    // rightCandle[i] = 位置 i（含）右边（含）最近的蜡烛索引，若无则 n
    std::vector<int> rightCandle(n, n);
    last = n;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '|') last = i;
        rightCandle[i] = last;
    }

    std::vector<int> result;
    result.reserve(queries.size());
    for (const auto& q : queries) {
        const int l = q[0], r = q[1];
        const int L = rightCandle[l];
        const int R = leftCandle[r];
        if (L < R) {
            result.push_back(prefix[R + 1] - prefix[L]);
        } else {
            result.push_back(0);
        }
    }
    return result;
}

PlatesBetweenCandlesSolution::PlatesBetweenCandlesSolution() {
    this->setMetaInfo({.id = 2055,
                       .title = "Plates Between Candles",
                       .url = "https://leetcode.com/problems/plates-between-candles/"});
    this->registerStrategy(
        {.name = "prefix-sum-and-nearest-candle",
         .expected = "Accepted",
         .time_complexity = "O(n + m)",
         .space_complexity = "O(n)",
         .tags = {"Array", "String", "Binary Search", "Prefix Sum"}},
        platesBetweenCandlesImpl);
}

std::vector<int> PlatesBetweenCandlesSolution::platesBetweenCandles(
    std::string s, std::vector<std::vector<int>>& queries) {
    return getSolution()(std::move(s), queries);
}

}  // namespace leetcode::problem_2055
