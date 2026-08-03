#ifndef LEETCODE_PROBLEMS_NUMBER_OF_ENCLAVES_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_ENCLAVES_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1020 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class NumberOfEnclavesSolution : public SolutionBase<Func> {
 public:
  NumberOfEnclavesSolution();

  int numEnclaves(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_1020
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_ENCLAVES_H_
