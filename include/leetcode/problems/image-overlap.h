#ifndef LEETCODE_PROBLEMS_IMAGE_OVERLAP_H__
#define LEETCODE_PROBLEMS_IMAGE_OVERLAP_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_835 {

using Func = std::function<int(std::vector<std::vector<int>>&,
                               std::vector<std::vector<int>>&)>;

class ImageOverlapSolution : public SolutionBase<Func> {
 public:
  ImageOverlapSolution();

  int largestOverlap(std::vector<std::vector<int>>& img1,
                     std::vector<std::vector<int>>& img2);
};

}  // namespace leetcode::problem_835

#endif  // LEETCODE_PROBLEMS_IMAGE_OVERLAP_H__
