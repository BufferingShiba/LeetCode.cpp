#ifndef LEETCODE_PROBLEMS_PERCENTAGE_OF_LETTER_IN_STRING_H__
#define LEETCODE_PROBLEMS_PERCENTAGE_OF_LETTER_IN_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2278 {

using Func = std::function<int(std::string, char)>;

class PercentageOfLetterInStringSolution
    : public SolutionBase<Func> {
 public:
  PercentageOfLetterInStringSolution();

  int percentageLetter(std::string s, char letter);
};

}  // namespace problem_2278
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PERCENTAGE_OF_LETTER_IN_STRING_H__
