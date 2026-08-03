#ifndef LEETCODE_PROBLEM_2767_H
#define LEETCODE_PROBLEM_2767_H

#include "leetcode/core.h"

namespace leetcode::problem_2767 {

using Func = std::function<int(std::string)>;

class PartitionStringIntoMinimumBeautifulSubstringsSolution : public SolutionBase<Func> {
 public:
  PartitionStringIntoMinimumBeautifulSubstringsSolution();
  int minimumBeautifulSubstrings(std::string s);
};

}  // namespace leetcode::problem_2767

#endif  // LEETCODE_PROBLEM_2767_H
