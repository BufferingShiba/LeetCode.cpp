#include "leetcode/problems/complex-number-multiplication.h"

#include <string>
#include <utility>

namespace leetcode {
namespace problem_537 {

namespace {

std::pair<int, int> Parse(const std::string& num) {
  const std::size_t plus = num.find('+');
  const int real = std::stoi(num.substr(0, plus));
  const int imaginary = std::stoi(num.substr(plus + 1, num.size() - plus - 2));
  return {real, imaginary};
}

std::string Multiply(const std::string& num1, const std::string& num2) {
  const auto [a, b] = Parse(num1);
  const auto [c, d] = Parse(num2);
  const int real = a * c - b * d;
  const int imaginary = a * d + b * c;
  return std::to_string(real) + "+" + std::to_string(imaginary) + "i";
}

}  // namespace

ComplexNumberMultiplicationSolution::ComplexNumberMultiplicationSolution() {
  setMetaInfo({.id = 537,
               .title = "Complex Number Multiplication",
               .url = "https://leetcode.com/problems/complex-number-multiplication/"});
  registerStrategy(
      {.name = "string-parse-multiply",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String", "Simulation"}},
      Multiply);
}

std::string ComplexNumberMultiplicationSolution::complexNumberMultiply(
    const std::string& num1, const std::string& num2) {
  return getSolution()(num1, num2);
}

}  // namespace problem_537
}  // namespace leetcode
