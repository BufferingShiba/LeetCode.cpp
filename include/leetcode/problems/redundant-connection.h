#ifndef LEETCODE_PROBLEMS_REDUNDANT_CONNECTION_H__
#define LEETCODE_PROBLEMS_REDUNDANT_CONNECTION_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_684 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class RedundantConnectionSolution : public SolutionBase<Func> {
 public:
  RedundantConnectionSolution();

  std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
    return getSolution()(edges);
  }

 private:
  void initStrategies();
  void registerStrategy(const std::string& name, const Func& func);
};

}  // namespace problem_684
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REDUNDANT_CONNECTION_H__
