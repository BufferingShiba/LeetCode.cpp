#ifndef LEETCODE_PROBLEMS_H_INDEX_II_H_
#define LEETCODE_PROBLEMS_H_INDEX_II_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_275 {

using Func = std::function<int(std::vector<int>&)>;

class HIndexIiSolution : public SolutionBase<Func> {
 public:
  HIndexIiSolution();

  int hIndex(std::vector<int>& citations);
};

}  // namespace problem_275
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_H_INDEX_II_H_
