#ifndef LEETCODE_PROBLEMS_SHUFFLE_STRING_H__
#define LEETCODE_PROBLEMS_SHUFFLE_STRING_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1528 {

using Func = std::function<std::string(std::string, std::vector<int>&)>;

class ShuffleStringSolution : public SolutionBase<Func> {
 public:
  ShuffleStringSolution();

  std::string restoreString(std::string s, std::vector<int>& indices);
};

}  // namespace leetcode::problem_1528

#endif  // LEETCODE_PROBLEMS_SHUFFLE_STRING_H__
