#include "leetcode/problems/parse-lisp-expression.h"

#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_736 {

namespace {

std::string readToken(const std::string& s, int& pos) {
  while (pos < static_cast<int>(s.size()) && s[pos] == ' ') pos++;
  int start = pos;
  while (pos < static_cast<int>(s.size()) && s[pos] != ' ' && s[pos] != ')') {
    pos++;
  }
  return s.substr(start, pos - start);
}

int evalToken(const std::string& token,
              std::vector<std::unordered_map<std::string, int>>& scope) {
  if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
    return std::stoi(token);
  }
  for (int i = static_cast<int>(scope.size()) - 1; i >= 0; i--) {
    auto it = scope[i].find(token);
    if (it != scope[i].end()) return it->second;
  }
  return 0;  // unreachable for valid input
}

int eval(const std::string& s, int& pos,
         std::vector<std::unordered_map<std::string, int>>& scope) {
  while (pos < static_cast<int>(s.size()) && s[pos] == ' ') pos++;

  if (s[pos] == '(') {
    pos++;  // skip '('
    std::string op = readToken(s, pos);
    int result = 0;

    if (op == "let") {
      scope.push_back({});
      while (true) {
        while (pos < static_cast<int>(s.size()) && s[pos] == ' ') pos++;
        if (s[pos] == ')') {
          break;  // should not happen for valid input
        }
        if (s[pos] == '(') {
          result = eval(s, pos, scope);
          break;
        }
        std::string token = readToken(s, pos);
        while (pos < static_cast<int>(s.size()) && s[pos] == ' ') pos++;
        if (s[pos] == ')') {
          result = evalToken(token, scope);
          break;
        }
        // token is a variable name, parse its value expression
        std::string var = token;
        int val = eval(s, pos, scope);
        scope.back()[var] = val;
      }
      scope.pop_back();
      pos++;  // skip ')'
      return result;
    } else if (op == "add") {
      int v1 = eval(s, pos, scope);
      int v2 = eval(s, pos, scope);
      pos++;  // skip ')'
      return v1 + v2;
    } else {  // mult
      int v1 = eval(s, pos, scope);
      int v2 = eval(s, pos, scope);
      pos++;  // skip ')'
      return v1 * v2;
    }
  } else {
    // integer literal or variable reference
    std::string token = readToken(s, pos);
    return evalToken(token, scope);
  }
}

int evaluateImpl(const std::string& expression) {
  int pos = 0;
  std::vector<std::unordered_map<std::string, int>> scope;
  return eval(expression, pos, scope);
}

}  // namespace

ParseLispExpressionSolution::ParseLispExpressionSolution() {
  setMetaInfo({.id = 736,
               .title = "Parse Lisp Expression",
               .url = "https://leetcode.com/problems/parse-lisp-expression/"});
  registerStrategy(
      {.name = "RecursiveDescent",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String", "Stack", "Recursion"}},
      evaluateImpl);
}

int ParseLispExpressionSolution::evaluate(std::string expression) {
  return getSolution()(expression);
}

}  // namespace problem_736
}  // namespace leetcode
