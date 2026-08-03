#ifndef LEETCODE_PROBLEMS_PALINDROME_PARTITIONING_III_H_
#define LEETCODE_PROBLEMS_PALINDROME_PARTITIONING_III_H_

#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1278 {

using Func = std::function<int(std::string, int)>;

class PalindromePartitioningIiiSolution : public SolutionBase<Func> {
 public:
  PalindromePartitioningIiiSolution();

  int palindromePartition(std::string s, int k);
};

}  // namespace leetcode::problem_1278

#endif  // LEETCODE_PROBLEMS_PALINDROME_PARTITIONING_III_H_
