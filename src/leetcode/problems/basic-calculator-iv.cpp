#include "leetcode/problems/basic-calculator-iv.h"

#include <algorithm>
#include <cctype>
#include <map>
#include <sstream>
#include <unordered_map>

namespace leetcode {
namespace problem_770 {
namespace {

using Variables = std::vector<std::string>;
using Polynomial = std::map<Variables, long long>;

void removeZeroTerms(Polynomial& polynomial) {
  for (auto it = polynomial.begin(); it != polynomial.end();) {
    if (it->second == 0) {
      it = polynomial.erase(it);
    } else {
      ++it;
    }
  }
}

Polynomial add(const Polynomial& lhs, const Polynomial& rhs, int sign) {
  Polynomial result = lhs;
  for (const auto& [variables, coefficient] : rhs) {
    result[variables] += sign * coefficient;
  }
  removeZeroTerms(result);
  return result;
}

Polynomial multiply(const Polynomial& lhs, const Polynomial& rhs) {
  Polynomial result;
  for (const auto& [leftVariables, leftCoefficient] : lhs) {
    for (const auto& [rightVariables, rightCoefficient] : rhs) {
      Variables variables = leftVariables;
      variables.insert(variables.end(), rightVariables.begin(),
                       rightVariables.end());
      std::sort(variables.begin(), variables.end());
      result[variables] += leftCoefficient * rightCoefficient;
    }
  }
  removeZeroTerms(result);
  return result;
}

std::vector<std::string> tokenize(const std::string& expression) {
  std::vector<std::string> tokens;
  for (std::size_t i = 0; i < expression.size();) {
    if (std::isspace(static_cast<unsigned char>(expression[i]))) {
      ++i;
      continue;
    }
    if (expression[i] == '(' || expression[i] == ')' ||
        expression[i] == '+' || expression[i] == '-' ||
        expression[i] == '*') {
      tokens.emplace_back(1, expression[i]);
      ++i;
      continue;
    }
    const std::size_t begin = i;
    while (i < expression.size() &&
           !std::isspace(static_cast<unsigned char>(expression[i])) &&
           expression[i] != '(' && expression[i] != ')' &&
           expression[i] != '+' && expression[i] != '-' &&
           expression[i] != '*') {
      ++i;
    }
    tokens.push_back(expression.substr(begin, i - begin));
  }
  return tokens;
}

Polynomial parseExpression(
    const std::vector<std::string>& tokens, std::size_t& index,
    const std::unordered_map<std::string, int>& values);

Polynomial parseFactor(const std::vector<std::string>& tokens,
                       std::size_t& index,
                       const std::unordered_map<std::string, int>& values) {
  if (tokens[index] == "(") {
    ++index;
    Polynomial result = parseExpression(tokens, index, values);
    ++index;  // ')'
    return result;
  }

  const std::string token = tokens[index++];
  if (!token.empty() && std::isdigit(static_cast<unsigned char>(token[0]))) {
    return Polynomial{{Variables{}, std::stoll(token)}};
  }

  const auto it = values.find(token);
  if (it != values.end()) {
    return Polynomial{{Variables{}, it->second}};
  }
  return Polynomial{{Variables{token}, 1}};
}

Polynomial parseTerm(const std::vector<std::string>& tokens,
                     std::size_t& index,
                     const std::unordered_map<std::string, int>& values) {
  Polynomial result = parseFactor(tokens, index, values);
  while (index < tokens.size() && tokens[index] == "*") {
    ++index;
    result = multiply(result, parseFactor(tokens, index, values));
  }
  return result;
}

Polynomial parseExpression(
    const std::vector<std::string>& tokens, std::size_t& index,
    const std::unordered_map<std::string, int>& values) {
  Polynomial result = parseTerm(tokens, index, values);
  while (index < tokens.size() &&
         (tokens[index] == "+" || tokens[index] == "-")) {
    const int sign = tokens[index++] == "+" ? 1 : -1;
    result = add(result, parseTerm(tokens, index, values), sign);
  }
  return result;
}

std::vector<std::string> format(const Polynomial& polynomial) {
  std::vector<std::pair<Variables, long long>> terms;
  for (const auto& term : polynomial) {
    if (term.second != 0) terms.push_back(term);
  }
  std::sort(terms.begin(), terms.end(),
            [](const auto& lhs, const auto& rhs) {
              if (lhs.first.size() != rhs.first.size()) {
                return lhs.first.size() > rhs.first.size();
              }
              return lhs.first < rhs.first;
            });

  std::vector<std::string> result;
  for (const auto& [variables, coefficient] : terms) {
    std::ostringstream term;
    term << coefficient;
    for (const std::string& variable : variables) {
      term << '*' << variable;
    }
    result.push_back(term.str());
  }
  return result;
}

std::vector<std::string> basicCalculatorIVImpl(
    std::string expression, std::vector<std::string>& evalvars,
    std::vector<int>& evalints) {
  std::unordered_map<std::string, int> values;
  for (std::size_t i = 0; i < evalvars.size(); ++i) {
    values[evalvars[i]] = evalints[i];
  }

  const std::vector<std::string> tokens = tokenize(expression);
  std::size_t index = 0;
  return format(parseExpression(tokens, index, values));
}

}  // namespace

BasicCalculatorIvSolution::BasicCalculatorIvSolution() {
  setMetaInfo({.id = 770,
               .title = "Basic Calculator IV",
               .url = "https://leetcode.com/problems/basic-calculator-iv/"});
  registerStrategy({.name = "recursive descent polynomial",
                    .expected = "Accepted",
                    .time_complexity = "O(N^3)",
                    .space_complexity = "O(N^2)",
                    .tags = {"Hash Table", "Math", "String", "Recursion"}},
                   basicCalculatorIVImpl);
}

std::vector<std::string> BasicCalculatorIvSolution::basicCalculatorIV(
    std::string expression, std::vector<std::string>& evalvars,
    std::vector<int>& evalints) {
  return getSolution()(std::move(expression), evalvars, evalints);
}

}  // namespace problem_770
}  // namespace leetcode
