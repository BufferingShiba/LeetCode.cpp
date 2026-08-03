#include "leetcode/problems/summary-ranges.h"

#include <string>
#include <vector>

namespace leetcode::problem_228 {

// 单次线性扫描，合并连续区间。
// 时间 O(n)，空间 O(n)（结果）。
static std::vector<std::string> summaryRangesImpl(std::vector<int>& nums) {
  std::vector<std::string> result;
  if (nums.empty()) {
    return result;
  }
  int start = nums[0];
  for (std::size_t i = 1; i < nums.size(); ++i) {
    // nums 唯一且递增，nums[i-1]+1 不会溢出。
    if (nums[i] != nums[i - 1] + 1) {
      if (start == nums[i - 1]) {
        result.push_back(std::to_string(start));
      } else {
        result.push_back(std::to_string(start) + "->" +
                         std::to_string(nums[i - 1]));
      }
      start = nums[i];
    }
  }
  if (start == nums.back()) {
    result.push_back(std::to_string(start));
  } else {
    result.push_back(std::to_string(start) + "->" + std::to_string(nums.back()));
  }
  return result;
}

SummaryRangesSolution::SummaryRangesSolution() {
  setMetaInfo({.id = 228, .title = "Summary Ranges", .url =
    "https://leetcode.com/problems/summary-ranges/"});
  registerStrategy(
      {.name = "LinearScan", .expected = "Accepted",
       .time_complexity = "O(n)", .space_complexity = "O(n)",
       .tags = {"Array"}}, summaryRangesImpl);
}

std::vector<std::string> SummaryRangesSolution::summaryRanges(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_228
