#pragma once
#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3850 {

using Func = std::function<int(std::vector<int>&, long long)>;

class CountSequencesToKSolution : public SolutionBase<Func> {
 public:
  CountSequencesToKSolution();
  int countSequences(std::vector<int>& nums, long long k);
};

}  // namespace problem_3850
}  // namespace leetcode
