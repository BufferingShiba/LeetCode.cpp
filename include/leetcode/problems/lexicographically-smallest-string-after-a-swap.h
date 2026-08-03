#ifndef LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_A_SWAP_H
#define LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_A_SWAP_H

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3216 {

using Func = std::function<std::string(std::string)>;

class LexicographicallySmallestStringAfterASwapSolution
    : public SolutionBase<Func> {
 public:
  LexicographicallySmallestStringAfterASwapSolution();

  std::string getSmallestString(std::string s);
};

}  // namespace leetcode::problem_3216

#endif  // LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_A_SWAP_H
