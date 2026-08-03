#ifndef LEETCODE_PROBLEMS_REMOVE_ELEMENT_H_
#define LEETCODE_PROBLEMS_REMOVE_ELEMENT_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_27 {

using Func = std::function<int(std::vector<int>&, int)>;

class RemoveElementSolution : public SolutionBase<Func> {
 public:
  RemoveElementSolution();

  int removeElement(std::vector<int>& nums, int val) {
    return getSolution()(nums, val);
  }
};

}  // namespace problem_27
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_ELEMENT_H_
