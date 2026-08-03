#ifndef LEETCODE_PROBLEMS_REARRANGE_CHARACTERS_TO_MAKE_TARGET_STRING_H__
#define LEETCODE_PROBLEMS_REARRANGE_CHARACTERS_TO_MAKE_TARGET_STRING_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_2287 {

using Func = std::function<int(std::string, std::string)>;

class RearrangeCharactersToMakeTargetStringSolution
    : public SolutionBase<Func> {
 public:
  RearrangeCharactersToMakeTargetStringSolution();

  int rearrangeCharacters(std::string s, std::string target);
};

}  // namespace problem_2287
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REARRANGE_CHARACTERS_TO_MAKE_TARGET_STRING_H__
