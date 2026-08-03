#include "leetcode/problems/score-validator.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3921 {

namespace {

std::vector<int> scoreValidatorImpl(std::vector<std::string>& events) {
  int score = 0;
  int counter = 0;
  for (const std::string& e : events) {
    if (e == "W") {
      ++counter;
      if (counter == 10) {
        break;
      }
    } else if (e == "WD" || e == "NB") {
      score += 1;
    } else {
      score += std::stoi(e);
    }
  }
  return {score, counter};
}

}  // namespace

ScoreValidatorSolution::ScoreValidatorSolution() {
  setMetaInfo({3921, "Score Validator",
               "https://leetcode.com/problems/score-validator/"});
  registerStrategy(
      {"SinglePassSimulation", "Accepted", "O(n)", "O(1)",
       {"Array", "String", "Simulation"}},
      scoreValidatorImpl);
}

std::vector<int> ScoreValidatorSolution::scoreValidator(
    std::vector<std::string>& events) {
  return getSolution()(events);
}

}  // namespace problem_3921
}  // namespace leetcode
