#include "leetcode/problems/count-number-of-homogenous-substrings.h"

#include <string>

namespace leetcode {
namespace problem_1759 {

namespace {
const long long kMod = 1000000007LL;
}  // namespace

int countHomogenousImpl(const std::string& s) {
  long long ans = 0;
  long long cnt = 1;  // 当前连续相同字符的个数
  for (std::size_t i = 1; i <= s.size(); ++i) {
    if (i < s.size() && s[i] == s[i - 1]) {
      ++cnt;
    } else {
      ans += cnt * (cnt + 1) / 2 % kMod;
      ans %= kMod;
      cnt = 1;
    }
  }
  return static_cast<int>(ans);
}

}  // namespace problem_1759
}  // namespace leetcode
