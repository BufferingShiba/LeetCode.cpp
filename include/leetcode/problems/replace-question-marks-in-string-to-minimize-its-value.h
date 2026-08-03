#ifndef LEETCODE_PROBLEMS_REPLACE_QUESTION_MARKS_IN_STRING_TO_MINIMIZE_ITS_VALUE_H_
#define LEETCODE_PROBLEMS_REPLACE_QUESTION_MARKS_IN_STRING_TO_MINIMIZE_ITS_VALUE_H_

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3081 {

class ReplaceQuestionMarksInStringToMinimizeItsValueSolution
    : public SolutionBase<std::function<std::string(std::string)>> {
 public:
  ReplaceQuestionMarksInStringToMinimizeItsValueSolution();
  std::string minimizeStringValue(std::string s);
};

}  // namespace problem_3081
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REPLACE_QUESTION_MARKS_IN_STRING_TO_MINIMIZE_ITS_VALUE_H_
