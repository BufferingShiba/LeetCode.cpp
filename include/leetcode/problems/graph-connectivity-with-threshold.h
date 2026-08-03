#ifndef LEETCODE_PROBLEMS_GRAPH_CONNECTIVITY_WITH_THRESHOLD_H__
#define LEETCODE_PROBLEMS_GRAPH_CONNECTIVITY_WITH_THRESHOLD_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1627 {

using Func = std::function<std::vector<bool>(int, int, std::vector<std::vector<int>>&)>;

class GraphConnectivityWithThreshold : public SolutionBase<Func> {
 public:
  GraphConnectivityWithThreshold();

  std::vector<bool> areConnected(int n, int threshold, std::vector<std::vector<int>>& queries);
};

}  // namespace problem_1627
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GRAPH_CONNECTIVITY_WITH_THRESHOLD_H__
