#ifndef LEETCODE_PROBLEMS_GREATEST_ENGLISH_LETTER_IN_UPPER_AND_LOWER_CASE_H
#define LEETCODE_PROBLEMS_GREATEST_ENGLISH_LETTER_IN_UPPER_AND_LOWER_CASE_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2309 {

using Func = std::function<std::string(std::string)>;

class GreatestEnglishLetterInUpperAndLowerCaseSolution : public SolutionBase<Func> {
 public:
  GreatestEnglishLetterInUpperAndLowerCaseSolution();

  std::string greatestLetter(std::string s);
};

}  // namespace problem_2309
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GREATEST_ENGLISH_LETTER_IN_UPPER_AND_LOWER_CASE_H
