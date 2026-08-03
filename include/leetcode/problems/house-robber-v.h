#ifndef LEETCODE_PROBLEMS_HOUSE_ROBBER_V_H
#define LEETCODE_PROBLEMS_HOUSE_ROBBER_V_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3840 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&)>;

class HouseRobberVSolution : public SolutionBase<Func> {
 public:
  HouseRobberVSolution();

  long long rob(std::vector<int>& nums, std::vector<int>& colors);
};

}  // namespace problem_3840
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_HOUSE_ROBBER_V_H
