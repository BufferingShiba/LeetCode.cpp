#include "leetcode/problems/fizz-buzz.h"

namespace leetcode {
namespace problem_412 {
namespace {

std::vector<std::string> fizzBuzzImpl(int n) {
  std::vector<std::string> answer;
  answer.reserve(n);
  for (int i = 1; i <= n; ++i) {
    if (i % 15 == 0) {
      answer.emplace_back("FizzBuzz");
    } else if (i % 3 == 0) {
      answer.emplace_back("Fizz");
    } else if (i % 5 == 0) {
      answer.emplace_back("Buzz");
    } else {
      answer.emplace_back(std::to_string(i));
    }
  }
  return answer;
}

}  // namespace

FizzBuzzSolution::FizzBuzzSolution() {
  setMetaInfo({412, "Fizz Buzz",
               "https://leetcode.com/problems/fizz-buzz/"});
  registerStrategy({.name = "simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "String", "Simulation"}},
                   fizzBuzzImpl);
}

std::vector<std::string> FizzBuzzSolution::fizzBuzz(int n) {
  return getSolution()(n);
}

}  // namespace problem_412
}  // namespace leetcode
