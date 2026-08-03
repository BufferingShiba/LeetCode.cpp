#ifndef LEETCODE_PROBLEMS_PALINDROME_PARTITIONING_H__
#define LEETCODE_PROBLEMS_PALINDROME_PARTITIONING_H__

#include "leetcode/core.h"

#include <string>
#include <vector>

namespace leetcode::problem_131 {

using Func = std::function<std::vector<std::vector<std::string>>(std::string)>;

class PalindromePartitioningSolution : public SolutionBase<Func> {
 public:
  PalindromePartitioningSolution();

  std::vector<std::vector<std::string>> partition(std::string s);
};

}  // namespace leetcode::problem_131

#endif  // LEETCODE_PROBLEMS_PALINDROME_PARTITIONING_H__
