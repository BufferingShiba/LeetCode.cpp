#include "leetcode/problems/reverse-pairs.h"

#include <vector>

namespace leetcode {
namespace problem_493 {

namespace {

int mergeSort(std::vector<int>& nums, std::vector<int>& temp, int left, int right) {
  if (left >= right) return 0;

  int mid = left + (right - left) / 2;
  int count =
      mergeSort(nums, temp, left, mid) + mergeSort(nums, temp, mid + 1, right);

  // 统计翻转对：对每个左半部分的 i，在右半部分找到第一个不满足 nums[i] > 2*nums[j] 的 j
  int j = mid + 1;
  for (int i = left; i <= mid; ++i) {
    while (j <= right &&
           static_cast<long long>(nums[i]) >
               2LL * static_cast<long long>(nums[j])) {
      ++j;
    }
    count += (j - (mid + 1));
  }

  // 归并两个有序子数组
  int i = left, k = left;
  j = mid + 1;
  while (i <= mid && j <= right) {
    if (nums[i] <= nums[j]) {
      temp[k++] = nums[i++];
    } else {
      temp[k++] = nums[j++];
    }
  }
  while (i <= mid) temp[k++] = nums[i++];
  while (j <= right) temp[k++] = nums[j++];

  for (i = left; i <= right; ++i) {
    nums[i] = temp[i];
  }

  return count;
}

int reversePairsImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  if (n < 2) return 0;
  std::vector<int> temp(n);
  return mergeSort(nums, temp, 0, n - 1);
}

}  // namespace

ReversePairsSolution::ReversePairsSolution() {
  setMetaInfo(
      {.id = 493,
       .title = "Reverse Pairs",
       .url = "https://leetcode.com/problems/reverse-pairs/"});
  registerStrategy(
      {.name = "MergeSort",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Divide and Conquer", "Merge Sort"}},
      reversePairsImpl);
  setDefaultStrategy();
}

int ReversePairsSolution::reversePairs(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_493
}  // namespace leetcode
