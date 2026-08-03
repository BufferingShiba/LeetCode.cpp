#ifndef LEETCODE_PROBLEMS_SMALLEST_SUBSTRING_WITH_IDENTICAL_CHARACTERS_II_H__
#define LEETCODE_PROBLEMS_SMALLEST_SUBSTRING_WITH_IDENTICAL_CHARACTERS_II_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3399 {

using Func = std::function<int(std::string&, int)>;

class SmallestSubstringWithIdenticalCharactersIiSolution
    : public SolutionBase<Func> {
 public:
  SmallestSubstringWithIdenticalCharactersIiSolution();

  int minLength(std::string s, int numOps);
};

}  // namespace problem_3399
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_SUBSTRING_WITH_IDENTICAL_CHARACTERS_II_H__
