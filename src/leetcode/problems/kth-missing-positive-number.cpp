#include "leetcode/problems/kth-missing-positive-number.h"

namespace leetcode {
namespace problem_1539 {

static int findKthPositiveImpl(std::vector<int>& arr, int k) {
    int left = 0, right = static_cast<int>(arr.size());
    while (left < right) {
        int mid = left + (right - left) / 2;
        // 到 arr[mid] 为止缺失的正整数个数
        int missing = arr[mid] - (mid + 1);
        if (missing < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    // left 是第一个使 missing >= k 的位置（若全部 < k 则 left == arr.size()）
    // 答案 = k + left（left 个元素之前缺失数不足 k，后面的从 arr[left-1]+1 开始数）
    return k + left;
}

KthMissingPositiveNumberSolution::KthMissingPositiveNumberSolution() {
    setMetaInfo({.id = 1539,
                 .title = "Kth Missing Positive Number",
                 .url = "https://leetcode.com/problems/kth-missing-positive-number/"});
    registerStrategy({.name = "binary_search",
                      .expected = "Accepted",
                      .time_complexity = "O(log n)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Binary Search"}},
                     findKthPositiveImpl);
}

int KthMissingPositiveNumberSolution::findKthPositive(std::vector<int>& arr, int k) {
    return getSolution()(arr, k);
}

}  // namespace problem_1539
}  // namespace leetcode
