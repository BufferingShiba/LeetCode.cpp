#ifndef LEETCODE_PROBLEMS_BEAUTIFUL_TOWERS_I_H__
#define LEETCODE_PROBLEMS_BEAUTIFUL_TOWERS_I_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2865 {

using Func = std::function<long long(std::vector<int>&)>;

class BeautifulTowersISolution : public SolutionBase<Func> {
 public:
  long long maximumSumOfHeights(std::vector<int>& heights);

  BeautifulTowersISolution();
};

}  // namespace problem_2865
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BEAUTIFUL_TOWERS_I_H__
