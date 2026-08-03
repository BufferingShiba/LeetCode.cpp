#ifndef LEETCODE_PROBLEMS_CHECK_IF_DFS_STRINGS_ARE_PALINDROMES_H__
#define LEETCODE_PROBLEMS_CHECK_IF_DFS_STRINGS_ARE_PALINDROMES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3327 {

using Func = std::function<std::vector<bool>(std::vector<int>&, std::string)>;

class CheckIfDfsStringsArePalindromesSolution : public SolutionBase<Func> {
 public:
  CheckIfDfsStringsArePalindromesSolution();
  std::vector<bool> findAnswer(std::vector<int>& parent, std::string s);
};

}  // namespace problem_3327
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_DFS_STRINGS_ARE_PALINDROMES_H__
