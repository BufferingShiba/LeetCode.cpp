#ifndef LEETCODE_PROBLEMS_REMOVING_MINIMUM_NUMBER_OF_MAGIC_BEANS_H_
#define LEETCODE_PROBLEMS_REMOVING_MINIMUM_NUMBER_OF_MAGIC_BEANS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2171 {

class RemovingMinimumNumberOfMagicBeansSolution : public SolutionBase<std::function<long long(std::vector<int>&)>> {
 public:
  using Base = SolutionBase<std::function<long long(std::vector<int>&)>>;
  using Func = std::function<long long(std::vector<int>&)>;

  RemovingMinimumNumberOfMagicBeansSolution();

  long long minimumRemoval(std::vector<int>& beans) {
    return getSolution()(beans);
  }
};

}  // namespace leetcode::problem_2171

#endif  // LEETCODE_PROBLEMS_REMOVING_MINIMUM_NUMBER_OF_MAGIC_BEANS_H_
