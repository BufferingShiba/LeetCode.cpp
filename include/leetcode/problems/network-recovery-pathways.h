#ifndef LEETCODE_PROBLEMS_NETWORK_RECOVERY_PATHWAYS_H__
#define LEETCODE_PROBLEMS_NETWORK_RECOVERY_PATHWAYS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3620 {

using Func =
    std::function<int(std::vector<std::vector<int>>&, std::vector<bool>&, long long)>;

class NetworkRecoveryPathwaysSolution
    : public SolutionBase<Func> {
 public:
  NetworkRecoveryPathwaysSolution();
};

}  // namespace problem_3620
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NETWORK_RECOVERY_PATHWAYS_H__
