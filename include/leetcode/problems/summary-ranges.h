#ifndef LEETCODE_PROBLEMS_SUMMARY_RANGES_H__
#define LEETCODE_PROBLEMS_SUMMARY_RANGES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_228 {

using Func = std::function<std::vector<std::string>(std::vector<int>&)>;

class SummaryRangesSolution : public SolutionBase<Func> {
 public:
  SummaryRangesSolution();
  std::vector<std::string> summaryRanges(std::vector<int>& nums);
};

}  // namespace leetcode::problem_228

#endif  // LEETCODE_PROBLEMS_SUMMARY_RANGES_H__
