#ifndef LEETCODE_PROBLEMS_PALINDROMIC_SUBSTRINGS_H__
#define LEETCODE_PROBLEMS_PALINDROMIC_SUBSTRINGS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_647 {

using Func = std::function<int(std::string)>;

class PalindromicSubstringsSolution : public SolutionBase<Func> {
 public:
  PalindromicSubstringsSolution();

  int countSubstrings(std::string s);
};

}  // namespace problem_647
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PALINDROMIC_SUBSTRINGS_H__
