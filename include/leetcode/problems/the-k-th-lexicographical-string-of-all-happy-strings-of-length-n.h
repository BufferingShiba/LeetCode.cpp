#ifndef LEETCODE_PROBLEMS_THE_K_TH_LEXICOGRAPHICAL_STRING_OF_ALL_HAPPY_STRINGS_OF_LENGTH_N_H__
#define LEETCODE_PROBLEMS_THE_K_TH_LEXICOGRAPHICAL_STRING_OF_ALL_HAPPY_STRINGS_OF_LENGTH_N_H__

#include "leetcode/core.h"
#include <string>

namespace leetcode::problem_1415 {

class TheKThLexicographicalStringOfAllHappyStringsOfLengthNSolution
    : public SolutionBase<std::function<std::string(int, int)>> {
 public:
  TheKThLexicographicalStringOfAllHappyStringsOfLengthNSolution();

  std::string getHappyString(int n, int k);
};

}  // namespace leetcode::problem_1415

#endif  // LEETCODE_PROBLEMS_THE_K_TH_LEXICOGRAPHICAL_STRING_OF_ALL_HAPPY_STRINGS_OF_LENGTH_N_H__
