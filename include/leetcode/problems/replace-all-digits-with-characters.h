#ifndef LEETCODE_PROBLEMS_REPLACE_ALL_DIGITS_WITH_CHARACTERS_H__
#define LEETCODE_PROBLEMS_REPLACE_ALL_DIGITS_WITH_CHARACTERS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1844 {

using Func = std::function<std::string(std::string)>;

class ReplaceAllDigitsWithCharactersSolution
    : public SolutionBase<Func> {
 public:
  ReplaceAllDigitsWithCharactersSolution();

  std::string replaceDigits(std::string s);
};

}  // namespace problem_1844
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REPLACE_ALL_DIGITS_WITH_CHARACTERS_H__
