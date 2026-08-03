#include "leetcode/problems/count-number-of-texts.h"

#include <string>
#include <vector>

namespace {

constexpr int MOD = 1000000007;

int countTextsImpl(const std::string& pressedKeys) {
  int n = static_cast<int>(pressedKeys.size());
  if (n == 0) return 0;

  // Precompute DP for both max_k = 3 and max_k = 4 up to n
  std::vector<long long> dp3(n + 1, 0);
  std::vector<long long> dp4(n + 1, 0);

  dp3[0] = 1;
  dp4[0] = 1;

  for (int i = 1; i <= n; ++i) {
    // max_k = 3
    dp3[i] = dp3[i - 1];
    if (i >= 2) dp3[i] = (dp3[i] + dp3[i - 2]) % MOD;
    if (i >= 3) dp3[i] = (dp3[i] + dp3[i - 3]) % MOD;

    // max_k = 4
    dp4[i] = dp4[i - 1];
    if (i >= 2) dp4[i] = (dp4[i] + dp4[i - 2]) % MOD;
    if (i >= 3) dp4[i] = (dp4[i] + dp4[i - 3]) % MOD;
    if (i >= 4) dp4[i] = (dp4[i] + dp4[i - 4]) % MOD;
  }

  long long result = 1;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && pressedKeys[j] == pressedKeys[i]) {
      ++j;
    }
    int len = j - i;
    char digit = pressedKeys[i];

    if (digit == '7' || digit == '9') {
      result = (result * dp4[len]) % MOD;
    } else {
      result = (result * dp3[len]) % MOD;
    }
    i = j;
  }

  return static_cast<int>(result);
}

}  // namespace

namespace leetcode {
namespace problem_2266 {

CountNumberOfTextsSolution::CountNumberOfTextsSolution() {
  setMetaInfo({.id = 2266,
               .title = "Count Number of Texts",
               .url = "https://leetcode.com/problems/count-number-of-texts/"});
  registerStrategy(
      {.name = "DP",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "String", "Math"}},
      countTextsImpl);
}

int CountNumberOfTextsSolution::countTexts(std::string pressedKeys) {
  return getSolution()(pressedKeys);
}

}  // namespace problem_2266
}  // namespace leetcode
