#ifndef LEETCODE_PROBLEMS_GOAL_PARSER_INTERPRETATION_H__
#define LEETCODE_PROBLEMS_GOAL_PARSER_INTERPRETATION_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1678 {

using Func = std::function<std::string(std::string)>;

class GoalParserInterpretationSolution : public SolutionBase<Func> {
 public:
  GoalParserInterpretationSolution();
  std::string interpret(std::string command);
};

}  // namespace problem_1678
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GOAL_PARSER_INTERPRETATION_H__
