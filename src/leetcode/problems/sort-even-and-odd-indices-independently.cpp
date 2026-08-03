#include "leetcode/problems/sort-even-and-odd-indices-independently.h"

namespace leetcode {
namespace problem_2164 {

static vector<int> sortEvenOddImpl(vector<int>& nums) {
  vector<int> even;
  vector<int> odd;
  even.reserve((nums.size() + 1) / 2);
  odd.reserve(nums.size() / 2);

  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    (i % 2 == 0 ? even : odd).push_back(nums[i]);
  }

  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end(), greater<int>());

  size_t even_index = 0;
  size_t odd_index = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    nums[i] = i % 2 == 0 ? even[even_index++] : odd[odd_index++];
  }
  return nums;
}

SortEvenAndOddIndicesIndependentlySolution::SortEvenAndOddIndicesIndependentlySolution() {
  setMetaInfo({
    .id = 2164,
    .title = "Sort Even and Odd Indices Independently",
    .url = "https://leetcode.com/problems/sort-even-and-odd-indices-independently/"
  });
  registerStrategy({
    .name = "Partition and Sort",
    .expected = "Accepted",
    .time_complexity = "O(n log n)",
    .space_complexity = "O(n)",
    .tags = {"Array", "Sorting"}
  }, sortEvenOddImpl);
}

vector<int> SortEvenAndOddIndicesIndependentlySolution::sortEvenOdd(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2164
}  // namespace leetcode
