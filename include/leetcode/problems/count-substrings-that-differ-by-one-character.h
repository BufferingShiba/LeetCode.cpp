#ifndef LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_DIFFER_BY_ONE_CHARACTER_H__
#define LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_DIFFER_BY_ONE_CHARACTER_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1638 {

using Func = std::function<int(std::string, std::string)>;

class CountSubstringsThatDifferByOneCharacterSolution
    : public SolutionBase<Func> {
 public:
  CountSubstringsThatDifferByOneCharacterSolution();
  int countSubstrings(std::string s, std::string t);
};

}  // namespace problem_1638
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_DIFFER_BY_ONE_CHARACTER_H__
