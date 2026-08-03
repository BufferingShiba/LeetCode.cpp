#ifndef LEETCODE_PROBLEMS_REMOVE_METHODS_FROM_PROJECT_H__
#define LEETCODE_PROBLEMS_REMOVE_METHODS_FROM_PROJECT_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3310 {

using Func = std::function<std::vector<int>(int, int, std::vector<std::vector<int>>&)>;

class RemoveMethodsFromProjectSolution : public SolutionBase<Func> {
 public:
  RemoveMethodsFromProjectSolution();

  std::vector<int> remainingMethods(int n, int k,
                                    std::vector<std::vector<int>>& invocations);
};

}  // namespace problem_3310
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_METHODS_FROM_PROJECT_H__
