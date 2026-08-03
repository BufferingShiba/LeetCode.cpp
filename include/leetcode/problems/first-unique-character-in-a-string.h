#ifndef LEETCODE_PROBLEMS_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H__
#define LEETCODE_PROBLEMS_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_387 {

using Func = std::function<int(std::string)>;

class FirstUniqueCharacterInAStringSolution
    : public SolutionBase<Func> {
 public:
  FirstUniqueCharacterInAStringSolution();

  int firstUniqChar(std::string s);
};

}  // namespace problem_387
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H__
