#include "leetcode/problems/count-of-integers.h"

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

namespace leetcode::problem_2719 {

namespace {

constexpr int64_t MOD = 1000000007LL;

// 计算 0 <= x <= num（十进制字符串）且数位和在 [min_sum, max_sum] 内的 x 的个数
int64_t countDigitSumLeq(const std::string& num, int min_sum, int max_sum) {
  if (max_sum < 0 || num.empty()) return 0;
  const int n = static_cast<int>(num.size());
  const int K = max_sum;
  // 记忆化搜索，结果对 MOD 取模。
  // memo[pos][sum][tight]: pos 表示当前处理位，sum 当前已累计数位和，tight 是否受限
  // 使用 int64_t，-1 表示未计算。
  std::vector<std::vector<std::vector<int64_t>>> memo(
      n + 1, std::vector<std::vector<int64_t>>(
                 K + 1, std::vector<int64_t>(2, -1)));

  std::function<int64_t(int, int, int)> dfs =
      [&](int pos, int sum, int tight) -> int64_t {
    if (sum > K) return 0;
    if (pos == n) {
      return sum >= min_sum ? 1LL : 0LL;
    }
    if (memo[pos][sum][tight] != -1) return memo[pos][sum][tight];
    int limit = tight ? (num[pos] - '0') : 9;
    int64_t res = 0;
    for (int d = 0; d <= limit; ++d) {
      res = (res +
             dfs(pos + 1, sum + d, tight && (d == limit))) %
            MOD;
    }
    return memo[pos][sum][tight] = res;
  };

  return dfs(0, 0, 1);
}

// 字符串数字减一
std::string subtractOne(const std::string& s) {
  std::string res = s;
  int i = static_cast<int>(res.size()) - 1;
  while (i >= 0 && res[i] == '0') {
    res[i--] = '9';
  }
  if (i < 0) {
    // 整个数字都是 0（这种情况 num1>=1 不会出现，但防御）
    return "";
  }
  res[i] = static_cast<char>(res[i] - 1);
  // 去掉前导零
  size_t pos = res.find_first_not_of('0');
  if (pos == std::string::npos) {
    return "0";
  }
  return res.substr(pos);
}

int countImpl(std::string num1, std::string num2, int min_sum, int max_sum) {
  int64_t up = countDigitSumLeq(num2, min_sum, max_sum);
  std::string prev = subtractOne(num1);
  int64_t down = (prev.empty() || prev == "0") ? 0LL
                                                : countDigitSumLeq(prev, min_sum, max_sum);
  if (prev == "") down = 0;
  int64_t ans = (up - down) % MOD;
  if (ans < 0) ans += MOD;
  return static_cast<int>(ans);
}

}  // namespace

CountOfIntegersSolution::CountOfIntegersSolution() {
  setMetaInfo({.id = 2719,
               .title = "Count of Integers",
               .url = "https://leetcode.com/problems/count-of-integers/"});
  registerStrategy({.name = "digit-dp",
                    .expected = "Accepted",
                    .time_complexity = "O(num_digits * max_sum * 10)",
                    .space_complexity = "O(num_digits * max_sum * 2)"},
                   countImpl);
}

int CountOfIntegersSolution::count(std::string num1, std::string num2, int min_sum,
                                   int max_sum) {
  return getSolution()(num1, num2, min_sum, max_sum);
}

}  // namespace leetcode::problem_2719
