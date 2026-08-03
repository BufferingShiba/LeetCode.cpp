#ifndef LEETCODE_PROBLEMS_BEAUTIFUL_ARRAY_H__
#define LEETCODE_PROBLEMS_BEAUTIFUL_ARRAY_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_932 {

using Func = std::function<std::vector<int>(int)>;

class BeautifulArraySolution : public SolutionBase<Func> {
 public:
  BeautifulArraySolution();

  std::vector<int> beautifulArray(int n);
};

}  // namespace problem_932
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BEAUTIFUL_ARRAY_H__
