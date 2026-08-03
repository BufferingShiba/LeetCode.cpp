#ifndef LEETCODE_PROBLEMS_MOST_FREQUENT_IDS_H__
#define LEETCODE_PROBLEMS_MOST_FREQUENT_IDS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3092 {

using Func = std::function<std::vector<long long>(std::vector<int>&, std::vector<int>&)>;

class MostFrequentIdsSolution : public SolutionBase<Func> {
 public:
  MostFrequentIdsSolution() {
    setMetaInfo({.id = 3092,
                 .title = "Most Frequent IDs",
                 .url = "https://leetcode.com/problems/most-frequent-ids/"});
    registerStrategy(
        {.name = "ordered-map-frequency-tracker",
         .expected = "Accepted",
         .time_complexity = "O(n log n)",
         .space_complexity = "O(n)",
         .tags = {"Hash Table", "Ordered Set"}},
        [](std::vector<int>& nums, std::vector<int>& freq) {
          return mostFrequentIDsImpl(nums, freq);
        });
  }

  std::vector<long long> mostFrequentIDs(std::vector<int>& nums,
                                         std::vector<int>& freq) {
    return getSolution()(nums, freq);
  }

 private:
  static std::vector<long long> mostFrequentIDsImpl(std::vector<int>& nums,
                                                    std::vector<int>& freq);
};

}  // namespace problem_3092
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MOST_FREQUENT_IDS_H__
