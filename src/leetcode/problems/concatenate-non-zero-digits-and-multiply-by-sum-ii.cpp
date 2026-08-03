#include "leetcode/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii.h"
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3756 {

namespace {
constexpr int MOD = 1000000007;

std::vector<int> sumAndMultiplyImpl(std::string s,
                                    std::vector<std::vector<int>>& queries) {
  int m = static_cast<int>(s.size());
  int q = static_cast<int>(queries.size());

  // 预处理 10 的幂
  std::vector<long long> pow10(m + 1);
  pow10[0] = 1;
  for (int i = 1; i <= m; ++i) {
    pow10[i] = pow10[i - 1] * 10 % MOD;
  }

  // 前缀：拼接值、非零个数、数字和
  std::vector<long long> pref_val(m + 1, 0);
  std::vector<int> pref_cnt(m + 1, 0);
  std::vector<int> pref_sum(m + 1, 0);

  for (int i = 0; i < m; ++i) {
    int d = s[i] - '0';
    pref_cnt[i + 1] = pref_cnt[i];
    pref_val[i + 1] = pref_val[i];
    pref_sum[i + 1] = pref_sum[i];
    if (d != 0) {
      pref_val[i + 1] = (pref_val[i] * 10 + d) % MOD;
      pref_cnt[i + 1] = pref_cnt[i] + 1;
      pref_sum[i + 1] = pref_sum[i] + d;
    }
  }

  std::vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    int l = queries[i][0];
    int r = queries[i][1];
    int cnt = pref_cnt[r + 1] - pref_cnt[l];
    if (cnt == 0) {
      ans[i] = 0;
    } else {
      long long b = pref_val[r + 1];
      long long a = pref_val[l];
      long long c = (b - a * pow10[cnt] % MOD + MOD) % MOD;
      int sum_digits = pref_sum[r + 1] - pref_sum[l];
      ans[i] = static_cast<int>(c * sum_digits % MOD);
    }
  }
  return ans;
}
}  // namespace

ConcatenateNonZeroDigitsAndMultiplyBySumIiSolution::
    ConcatenateNonZeroDigitsAndMultiplyBySumIiSolution() {
  setMetaInfo(
      {.id = 3756,
       .title = "Concatenate Non-Zero Digits and Multiply by Sum II",
       .url = "https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/"});
  registerStrategy({.name = "PrefixSum",
                    .expected = "Accepted",
                    .time_complexity = "O(m + q)",
                    .space_complexity = "O(m)",
                    .tags = {"Math", "String", "Prefix Sum"}},
                   sumAndMultiplyImpl);
}

std::vector<int> ConcatenateNonZeroDigitsAndMultiplyBySumIiSolution::sumAndMultiply(
    std::string s, std::vector<std::vector<int>>& queries) {
  return getSolution()(s, queries);
}

}  // namespace problem_3756
}  // namespace leetcode
