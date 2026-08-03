#ifndef LEETCODE_PROBLEMS_IDENTIFY_THE_LARGEST_OUTLIER_IN_AN_ARRAY_H_
#define LEETCODE_PROBLEMS_IDENTIFY_THE_LARGEST_OUTLIER_IN_AN_ARRAY_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3371 {

using Func = std::function<int(std::vector<int>&)>;

class IdentifyTheLargestOutlierInAnArraySolution : public SolutionBase<Func> {
 public:
  IdentifyTheLargestOutlierInAnArraySolution();

  int getLargestOutlier(std::vector<int>& nums);
};

}  // namespace problem_3371
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_IDENTIFY_THE_LARGEST_OUTLIER_IN_AN_ARRAY_H_
