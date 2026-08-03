#ifndef LEETCODE_PROBLEMS_NUMBER_OF_OPERATIONS_TO_MAKE_NETWORK_CONNECTED_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_OPERATIONS_TO_MAKE_NETWORK_CONNECTED_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1319 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class NumberOfOperationsToMakeNetworkConnectedSolution : public SolutionBase<Func> {
 public:
  NumberOfOperationsToMakeNetworkConnectedSolution();
  int makeConnected(int n, std::vector<std::vector<int>>& connections);
};

}  // namespace problem_1319
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_OPERATIONS_TO_MAKE_NETWORK_CONNECTED_H_
