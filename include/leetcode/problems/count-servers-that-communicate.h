#ifndef PROBLEM_1267_COUNT_SERVERS_THAT_COMMUNICATE_H__
#define PROBLEM_1267_COUNT_SERVERS_THAT_COMMUNICATE_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1267 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CountServersThatCommunicateSolution
    : public SolutionBase<Func> {
 public:
  CountServersThatCommunicateSolution();

  int countServers(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_1267
}  // namespace leetcode

#endif  // PROBLEM_1267_COUNT_SERVERS_THAT_COMMUNICATE_H__
