#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_STEPS_TO_MAKE_TWO_STRINGS_ANAGRAM_II_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_STEPS_TO_MAKE_TWO_STRINGS_ANAGRAM_II_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2186 {

using Func = std::function<int(std::string, std::string)>;

class MinimumNumberOfStepsToMakeTwoStringsAnagramIiSolution
    : public SolutionBase<Func> {
 public:
  int minSteps(std::string s, std::string t);

  MinimumNumberOfStepsToMakeTwoStringsAnagramIiSolution();
};

}  // namespace leetcode::problem_2186

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_STEPS_TO_MAKE_TWO_STRINGS_ANAGRAM_II_H_
