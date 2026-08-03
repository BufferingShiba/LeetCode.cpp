#ifndef LEETCODE_PROBLEM_NETWORKDELAYTIME_H
#define LEETCODE_PROBLEM_NETWORKDELAYTIME_H

#include "leetcode/core.h"

#include <vector>
#include <functional>

namespace leetcode {
namespace problem_743 {

using Func = std::function<int(std::vector<std::vector<int>>&, int, int)>;

class NetworkDelayTimeSolution : public SolutionBase<Func> {
 public:
  NetworkDelayTimeSolution();

  int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k);
};

}  // namespace problem_743
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_NETWORKDELAYTIME_H
