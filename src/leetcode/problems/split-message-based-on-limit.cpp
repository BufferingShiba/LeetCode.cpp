#include "leetcode/problems/split-message-based-on-limit.h"

namespace leetcode {
namespace problem_2468 {
namespace {

int countDigits(long long x) {
  int d = 0;
  while (x > 0) {
    ++d;
    x /= 10;
  }
  return d;
}

// Sum of the number of digits of the integers 1..b.
long long sumDigitsUpTo(long long b) {
  long long s = 0;
  long long power = 1;
  int d = 1;
  while (power * 10 <= b) {
    // numbers with exactly d digits: from power to power*10 - 1, count = 9*power
    s += d * (9 * power);
    power *= 10;
    ++d;
  }
  s += d * (b - power + 1);
  return s;
}

std::vector<std::string> splitMessageStrat(std::string message, int limit) {
  const int n = static_cast<int>(message.size());

  for (int b = 1; b <= n; ++b) {
    const int db = countDigits(b);
    int maxLenLast = limit - (2 * db + 3);  // content length for a == b
    if (maxLenLast < 0) continue;            // suffix too long for every part

    // maxLen(a) = limit - (digits(a) + db + 3)
    // contentSum = sum_{a=1..b} maxLen(a) = b*limit - b*(db+3) - sumDigitsUpTo(b)
    long long contentSum = static_cast<long long>(b) * limit -
                           static_cast<long long>(b) * (db + 3) -
                           sumDigitsUpTo(b);
    long long forcedSum = contentSum - maxLenLast;  // non-last parts fixed length

    if (forcedSum > n) continue;
    if (contentSum < n) continue;

    // Feasible with exactly b parts: construct the answer.
    std::vector<std::string> res;
    res.reserve(b);
    int idx = 0;
    for (int a = 1; a <= b; ++a) {
      std::string suffix = "<" + std::to_string(a) + "/" + std::to_string(b) + ">";
      int maxLen = limit - static_cast<int>(suffix.size());
      int take = (a == b) ? (n - idx) : maxLen;
      res.push_back(message.substr(idx, take) + suffix);
      idx += take;
    }
    return res;
  }

  return {};
}

}  // namespace

SplitMessageBasedOnLimitSolution::SplitMessageBasedOnLimitSolution() {
  setMetaInfo({.id = 2468,
               .title = "Split Message Based on Limit",
               .url = "https://leetcode.com/problems/split-message-based-on-limit/"});
  registerStrategy({.name = "enumerate-parts",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String", "Enumeration"}},
                   splitMessageStrat);
}

std::vector<std::string> SplitMessageBasedOnLimitSolution::splitMessage(std::string message, int limit) {
  return getSolution()(std::move(message), limit);
}

}  // namespace problem_2468
}  // namespace leetcode
