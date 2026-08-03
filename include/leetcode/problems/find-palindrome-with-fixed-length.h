#ifndef LEETCODE_PROBLEMS_FIND_PALINDROME_WITH_FIXED_LENGTH_H__
#define LEETCODE_PROBLEMS_FIND_PALINDROME_WITH_FIXED_LENGTH_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2217 {

using Func = std::function<std::vector<long long>(std::vector<int>&, int)>;

class FindPalindromeWithFixedLengthSolution : public SolutionBase<Func> {
 public:
  FindPalindromeWithFixedLengthSolution();

  std::vector<long long> kthPalindrome(std::vector<int>& queries, int intLength);
};

}  // namespace leetcode::problem_2217

#endif  // LEETCODE_PROBLEMS_FIND_PALINDROME_WITH_FIXED_LENGTH_H__
