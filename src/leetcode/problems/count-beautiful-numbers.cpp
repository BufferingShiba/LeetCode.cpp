#include "leetcode/problems/count-beautiful-numbers.h"

#include <cstring>
#include <vector>

namespace leetcode::problem_3490 {

namespace {

// memo[pos][tight][cur_sum][prod_mod][started]
// Dimensions: pos(0..9), tight(0..1), cur_sum(0..81), prod_mod(0..80), started(0..1)
int memo[10][2][82][81][2];

int dfs(const std::vector<int>& digits, int pos, bool tight,
        int cur_sum, int prod_mod, bool started, int target_sum) {
  if (pos == static_cast<int>(digits.size())) {
    return (started && cur_sum == target_sum && prod_mod == 0) ? 1 : 0;
  }
  if (cur_sum > target_sum) {
    return 0;
  }

  int& ref = memo[pos][tight][cur_sum][prod_mod][started];
  if (ref != -1) {
    return ref;
  }

  int limit = tight ? digits[pos] : 9;
  int ans = 0;
  for (int d = 0; d <= limit; ++d) {
    int new_sum = cur_sum + d;
    if (new_sum > target_sum) {
      continue;
    }
    bool new_tight = tight && (d == limit);

    if (!started && d == 0) {
      // Still leading zeros; sum=0, product=1 (identity).
      ans += dfs(digits, pos + 1, new_tight, 0, 0, false, target_sum);
    } else {
      int new_prod_mod;
      if (!started) {
        // First non-zero digit
        new_prod_mod = d % target_sum;
      } else {
        // Subsequent digits (including zero, which makes product=0)
        new_prod_mod = (prod_mod * d) % target_sum;
      }
      ans += dfs(digits, pos + 1, new_tight, new_sum, new_prod_mod, true,
                 target_sum);
    }
  }
  return ref = ans;
}

int countBeautifulUpTo(int n) {
  if (n <= 0) {
    return 0;
  }

  std::vector<int> digits;
  int temp = n;
  while (temp > 0) {
    digits.insert(digits.begin(), temp % 10);
    temp /= 10;
  }

  int len = static_cast<int>(digits.size());
  int max_sum = 9 * len;
  int total = 0;
  for (int s = 1; s <= max_sum; ++s) {
    std::memset(memo, -1, sizeof(memo));
    total += dfs(digits, 0, true, 0, 0, false, s);
  }
  return total;
}

int beautifulNumbersImpl(int l, int r) {
  return countBeautifulUpTo(r) - countBeautifulUpTo(l - 1);
}

}  // namespace

int CountBeautifulNumbersSolution::beautifulNumbers(int l, int r) {
  return getSolution()(l, r);
}

CountBeautifulNumbersSolution::CountBeautifulNumbersSolution() {
  setMetaInfo({.id = 3490,
               .title = "Count Beautiful Numbers",
               .url = "https://leetcode.com/problems/count-beautiful-numbers/"});
  registerStrategy(
      {.name = "DigitDP",
       .expected = "Accepted",
       .time_complexity = "O(81 * D * S^2)",
       .space_complexity = "O(D * S^2)",
       .tags = {"Dynamic Programming", "Digit DP"}},
      beautifulNumbersImpl);
}

}  // namespace leetcode::problem_3490
