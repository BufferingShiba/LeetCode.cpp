#ifndef LEETCODE_PROBLEMS_FIND_FIRST_PALINDROMIC_STRING_IN_THE_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_FIRST_PALINDROMIC_STRING_IN_THE_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2108 {

class FindFirstPalindromicStringInTheArraySolution
    : public SolutionBase<std::function<std::string(std::vector<std::string>&)>> {
 public:
  FindFirstPalindromicStringInTheArraySolution();

  std::string firstPalindrome(std::vector<std::string>& words);
};

}  // namespace problem_2108
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_FIRST_PALINDROMIC_STRING_IN_THE_ARRAY_H__
