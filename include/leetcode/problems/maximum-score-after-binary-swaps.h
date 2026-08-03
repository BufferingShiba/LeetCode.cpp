#ifndef LEETCODE_PROBLEM_3781_H_
#define LEETCODE_PROBLEM_3781_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3781 {

using Func = std::function<long long(std::vector<int>&, std::string)>;

class MaximumScoreAfterBinarySwapsSolution : public SolutionBase<Func> {
 public:
  MaximumScoreAfterBinarySwapsSolution();

  long long maximumScore(std::vector<int>& nums, std::string s);
};

}  // namespace problem_3781
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3781_H_
