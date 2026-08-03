#ifndef LEETCODE_PROBLEM_832_FLIPPING_AN_IMAGE_H_
#define LEETCODE_PROBLEM_832_FLIPPING_AN_IMAGE_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_832 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class FlippingAnImageSolution : public SolutionBase<Func> {
 public:
  FlippingAnImageSolution();
  std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image);
};

}  // namespace problem_832
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_832_FLIPPING_AN_IMAGE_H_
