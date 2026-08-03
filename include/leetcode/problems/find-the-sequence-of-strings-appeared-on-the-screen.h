#ifndef LEETCODE_PROBLEMS_FIND_THE_SEQUENCE_OF_STRINGS_APPEARED_ON_THE_SCREEN_H_
#define LEETCODE_PROBLEMS_FIND_THE_SEQUENCE_OF_STRINGS_APPEARED_ON_THE_SCREEN_H_

#include "leetcode/core.h"

namespace leetcode::problem_3324 {

using Func = std::function<std::vector<std::string>(std::string)>;

class FindTheSequenceOfStringsAppearedOnTheScreenSolution : public SolutionBase<Func> {
 public:
  FindTheSequenceOfStringsAppearedOnTheScreenSolution();

  std::vector<std::string> stringSequence(std::string target);
};

}  // namespace leetcode::problem_3324

#endif  // LEETCODE_PROBLEMS_FIND_THE_SEQUENCE_OF_STRINGS_APPEARED_ON_THE_SCREEN_H_
