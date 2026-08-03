#ifndef LEETCODE_PROBLEM_1054_H_
#define LEETCODE_PROBLEM_1054_H_

#include "leetcode/core.h"

namespace leetcode::problem_1054 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class DistantBarcodesSolution : public SolutionBase<Func> {
 public:
  DistantBarcodesSolution();

  std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes);
};

}  // namespace leetcode::problem_1054

#endif  // LEETCODE_PROBLEM_1054_H_
