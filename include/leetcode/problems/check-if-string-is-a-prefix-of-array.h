#ifndef LEETCODE_PROBLEMS_CHECK_IF_STRING_IS_A_PREFIX_OF_ARRAY_H_
#define LEETCODE_PROBLEMS_CHECK_IF_STRING_IS_A_PREFIX_OF_ARRAY_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1961 {

using Func = std::function<bool(std::string, std::vector<std::string>&)>;

class CheckIfStringIsAPrefixOfArraySolution : public SolutionBase<Func> {
 public:
  CheckIfStringIsAPrefixOfArraySolution();

  bool isPrefixString(std::string s, std::vector<std::string>& words);
};

}  // namespace problem_1961
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_STRING_IS_A_PREFIX_OF_ARRAY_H_
