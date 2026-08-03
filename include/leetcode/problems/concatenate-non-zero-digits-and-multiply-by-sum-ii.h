#ifndef LEETCODE_PROBLEM_3756_H
#define LEETCODE_PROBLEM_3756_H

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3756 {

using Func = std::function<std::vector<int>(std::string, std::vector<std::vector<int>>&)>;

class ConcatenateNonZeroDigitsAndMultiplyBySumIiSolution : public SolutionBase<Func> {
 public:
  ConcatenateNonZeroDigitsAndMultiplyBySumIiSolution();

  std::vector<int> sumAndMultiply(std::string s, std::vector<std::vector<int>>& queries);
};

}  // namespace problem_3756
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3756_H
