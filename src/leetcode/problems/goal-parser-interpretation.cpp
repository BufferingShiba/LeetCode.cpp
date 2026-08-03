#include "leetcode/problems/goal-parser-interpretation.h"

#include <string>

namespace leetcode {
namespace problem_1678 {

namespace {
std::string interpretImpl(std::string command) {
  std::string result;
  int i = 0;
  const int n = static_cast<int>(command.size());
  while (i < n) {
    if (command[i] == 'G') {
      result += 'G';
      ++i;
    } else {
      if (command[i + 1] == ')') {
        result += 'o';
        i += 2;
      } else {
        result += "al";
        i += 4;
      }
    }
  }
  return result;
}
}  // namespace

GoalParserInterpretationSolution::GoalParserInterpretationSolution() {
  setMetaInfo({.id = 1678,
               .title = "Goal Parser Interpretation",
               .url = "https://leetcode.com/problems/goal-parser-interpretation/"});
  registerStrategy({.name = "SingleScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String", "Simulation"}},
                   interpretImpl);
}

std::string GoalParserInterpretationSolution::interpret(std::string command) {
  return getSolution()(std::move(command));
}

}  // namespace problem_1678
}  // namespace leetcode
