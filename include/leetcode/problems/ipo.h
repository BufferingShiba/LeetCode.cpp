#ifndef LEETCODE_PROBLEMS_IPO_H_
#define LEETCODE_PROBLEMS_IPO_H_

#include <functional>
#include <vector>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_502 {

using Func = std::function<int(int, int, std::vector<int>&, std::vector<int>&)>;

class IpoSolution : public SolutionBase<Func> {
 public:
  IpoSolution();

  int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital);
};

}  // namespace problem_502
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_IPO_H_
