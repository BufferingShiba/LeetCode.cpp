#ifndef LEETCODE_PROBLEMS_LARGEST_SUBSTRING_BETWEEN_TWO_EQUAL_CHARACTERS_H__
#define LEETCODE_PROBLEMS_LARGEST_SUBSTRING_BETWEEN_TWO_EQUAL_CHARACTERS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_1624 {

using Func = std::function<int(std::string s)>;

class LargestSubstringBetweenTwoEqualCharactersSolution
    : public SolutionBase<Func> {
 public:
  LargestSubstringBetweenTwoEqualCharactersSolution();

  int maxLengthBetweenEqualCharacters(std::string s);
};

}  // namespace leetcode::problem_1624

#endif  // LEETCODE_PROBLEMS_LARGEST_SUBSTRING_BETWEEN_TWO_EQUAL_CHARACTERS_H__
