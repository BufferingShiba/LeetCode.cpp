#include "leetcode/problems/check-if-numbers-are-ascending-in-a-sentence.h"

#include <cctype>
#include <sstream>

namespace leetcode {
namespace problem_2042 {

namespace {

bool areNumbersAscendingImpl(std::string s) {
  std::istringstream iss(std::move(s));
  std::string token;
  int prev = -1;
  bool hasPrev = false;
  while (iss >> token) {
    if (std::isdigit(static_cast<unsigned char>(token[0]))) {
      int value = std::stoi(token);
      if (hasPrev && value <= prev) {
        return false;
      }
      prev = value;
      hasPrev = true;
    }
  }
  return true;
}

}  // namespace

CheckIfNumbersAreAscendingInASentenceSolution::
    CheckIfNumbersAreAscendingInASentenceSolution() {
  setMetaInfo({2042, "Check if Numbers Are Ascending in a Sentence",
               "https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/"});
  registerStrategy(
      {.name = "stringstream-scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Parsing"}},
      areNumbersAscendingImpl);
}

bool CheckIfNumbersAreAscendingInASentenceSolution::areNumbersAscending(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_2042
}  // namespace leetcode
