#ifndef LEETCODE_PROBLEMS_PROPERTIES_GRAPH_H_
#define LEETCODE_PROBLEMS_PROPERTIES_GRAPH_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3493 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class PropertiesGraphSolution : public SolutionBase<Func> {
 public:
  PropertiesGraphSolution();
  int numberOfComponents(std::vector<std::vector<int>>& properties, int k);
};

}  // namespace problem_3493
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PROPERTIES_GRAPH_H_
