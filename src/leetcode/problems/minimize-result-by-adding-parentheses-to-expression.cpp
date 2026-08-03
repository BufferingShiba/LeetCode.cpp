#include "leetcode/problems/minimize-result-by-adding-parentheses-to-expression.h"

#include <string>
#include <limits>

namespace leetcode {
namespace problem_2232 {

namespace {

// 空字符串视为 1；否则解析为整数。
long long parseOrOne(const std::string& s) {
  if (s.empty()) return 1LL;
  return std::stoll(s);
}

std::string minimizeResultImpl(std::string expression) {
  const std::size_t plus = expression.find('+');
  const std::string left = expression.substr(0, plus);
  const std::string right = expression.substr(plus + 1);

  long long best = std::numeric_limits<long long>::max();
  std::string bestExpr;

  // i: left 中 ')' 之前 '(' 所在位置切分 -> A = left[0..i), B = left[i..)
  // The parenthesized left and right operands must both be non-empty.
  for (std::size_t i = 0; i < left.size(); ++i) {
    const std::string a = left.substr(0, i);
    const std::string b = left.substr(i);
    for (std::size_t j = 1; j <= right.size(); ++j) {
      const std::string c = right.substr(0, j);
      const std::string d = right.substr(j);
      long long val = parseOrOne(a) * (parseOrOne(b) + parseOrOne(c)) * parseOrOne(d);
      if (val < best) {
        best = val;
        bestExpr = a + "(" + b + "+" + c + ")" + d;
      }
    }
  }
  return bestExpr;
}

}  // namespace

MinimizeResultByAddingParenthesesToExpressionSolution::MinimizeResultByAddingParenthesesToExpressionSolution() {
  setMetaInfo({.id = 2232,
               .title = "Minimize Result by Adding Parentheses to Expression",
               .url = "https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/"});
  registerStrategy({.name = "EnumerateParentheses",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Enumeration"}},
                   minimizeResultImpl);
}

std::string MinimizeResultByAddingParenthesesToExpressionSolution::minimizeResult(std::string expression) {
  return getSolution()(std::move(expression));
}

}  // namespace problem_2232
}  // namespace leetcode
