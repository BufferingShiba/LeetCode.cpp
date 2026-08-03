#ifndef LEETCODE_PROBLEMS_MAXIMUM_STRONG_PAIR_XOR_I_H__
#define LEETCODE_PROBLEMS_MAXIMUM_STRONG_PAIR_XOR_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2932 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumStrongPairXorISolution
    : public SolutionBase<Func> {
 public:
  MaximumStrongPairXorISolution();

  int maximumStrongPairXor(std::vector<int>& nums);
};

}  // namespace problem_2932
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_STRONG_PAIR_XOR_I_H__
