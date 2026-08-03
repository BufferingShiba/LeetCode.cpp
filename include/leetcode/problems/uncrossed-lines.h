#ifndef LEETCODE_PROBLEMS_UNCROSSED_LINES_H__
#define LEETCODE_PROBLEMS_UNCROSSED_LINES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1035 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class UncrossedLinesSolution : public SolutionBase<Func> {
 public:
  UncrossedLinesSolution();
  int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2);
};

}  // namespace problem_1035
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_UNCROSSED_LINES_H__
