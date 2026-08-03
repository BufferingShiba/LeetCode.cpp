#ifndef LEETCODE_PROBLEMS_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H_
#define LEETCODE_PROBLEMS_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H_

#include <vector>
#include <string>
#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_1177 {

using Func = std::function<std::vector<bool>(std::string, std::vector<std::vector<int>>&)>;

class CanMakePalindromeFromSubstringSolution : public SolutionBase<Func> {
 public:
  CanMakePalindromeFromSubstringSolution();

  std::vector<bool> canMakePaliQueries(std::string s, std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_1177

#endif  // LEETCODE_PROBLEMS_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H_
