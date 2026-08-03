#include "leetcode/problems/expression-add-operators.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_282 {

namespace {

void backtrack(const std::string& num, int target, std::size_t index,
               long long cur, long long prev, std::string expr,
               std::vector<std::string>& result) {
  if (index == num.size()) {
    if (cur == static_cast<long long>(target)) {
      result.push_back(std::move(expr));
    }
    return;
  }

  for (std::size_t len = 1; len <= num.size() - index; ++len) {
    std::string sub = num.substr(index, len);
    long long val = std::stoll(sub);

    // 前导零检查：多位数不能以 '0' 开头
    if (sub[0] == '0' && len > 1) {
      break;
    }

    if (index == 0) {
      // 第一个操作数，无需运算符
      backtrack(num, target, index + len, val, val, sub, result);
    } else {
      // 加法
      backtrack(num, target, index + len, cur + val, val,
                expr + "+" + sub, result);
      // 减法
      backtrack(num, target, index + len, cur - val, -val,
                expr + "-" + sub, result);
      // 乘法：cur - prev + prev * val
      backtrack(num, target, index + len, cur - prev + prev * val,
                prev * val, expr + "*" + sub, result);
    }
  }
}

std::vector<std::string> addOperatorsImpl(std::string num, int target) {
  std::vector<std::string> result;
  if (num.empty()) {
    return result;
  }
  backtrack(num, target, 0, 0, 0, "", result);
  return result;
}

}  // namespace

ExpressionAddOperatorsSolution::ExpressionAddOperatorsSolution() {
  setMetaInfo({.id = 282,
               .title = "Expression Add Operators",
               .url = "https://leetcode.com/problems/expression-add-operators/"});

  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(3^n * n)",
       .space_complexity = "O(3^n * n)",
       .tags = {"Math", "String", "Backtracking"}},
      addOperatorsImpl);
}

std::vector<std::string> ExpressionAddOperatorsSolution::addOperators(
    std::string num, int target) {
  return getSolution()(num, target);
}

}  // namespace problem_282
}  // namespace leetcode
