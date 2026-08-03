#ifndef LEETCODE_PROBLEM_2183_H_
#define LEETCODE_PROBLEM_2183_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2183 {

using Func = std::function<long long(std::vector<int>&, int)>;

class CountArrayPairsDivisibleByKSolution : public SolutionBase<Func> {
 public:
  CountArrayPairsDivisibleByKSolution();
  long long countPairs(std::vector<int>& nums, int k);
};

}  // namespace problem_2183
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2183_H_
