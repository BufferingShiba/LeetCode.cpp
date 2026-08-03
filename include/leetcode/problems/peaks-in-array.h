#ifndef LEETCODE_PROBLEMS_PEAKS_IN_ARRAY_H__
#define LEETCODE_PROBLEMS_PEAKS_IN_ARRAY_H__

#include <vector>
using std::vector;

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3187 {

using Func = std::function<vector<int>(vector<int>&, vector<vector<int>>&)>;

class PeaksInArraySolution : public SolutionBase<Func> {
 public:
  PeaksInArraySolution();

  vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries);
};

}  // namespace problem_3187
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PEAKS_IN_ARRAY_H__
