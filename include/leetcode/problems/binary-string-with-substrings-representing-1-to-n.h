#ifndef LEETCODE_PROBLEMS_BINARY_STRING_WITH_SUBSTRINGS_REPRESENTING_1_TO_N_H__
#define LEETCODE_PROBLEMS_BINARY_STRING_WITH_SUBSTRINGS_REPRESENTING_1_TO_N_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1016 {

using Func = std::function<bool(const std::string&, int)>;

class BinaryStringWithSubstringsRepresenting1ToNSolution
    : public SolutionBase<Func> {
 public:
  BinaryStringWithSubstringsRepresenting1ToNSolution();

  bool queryString(const std::string& s, int n);
};

}  // namespace leetcode::problem_1016

#endif  // LEETCODE_PROBLEMS_BINARY_STRING_WITH_SUBSTRINGS_REPRESENTING_1_TO_N_H__
