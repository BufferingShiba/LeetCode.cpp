
#include "leetcode/problems/valid-mountain-array.h"

namespace leetcode {
namespace problem_941 {

// 双指针 + 单次遍历：从两侧同时向峰值攀爬
// 时间复杂度: O(n), 空间复杂度: O(1)
static bool solution1(vector<int>& arr) {
  const int n = arr.size();
  if (n < 3) return false;

  int l = 0;
  int r = n - 1;

  // 从左往右找严格递增峰（左侧爬坡）
  while (l + 1 < n && arr[l] < arr[l + 1]) {
    ++l;
  }
  // 从右往左找严格递减峰（右侧爬坡）
  while (r - 1 >= 0 && arr[r] < arr[r - 1]) {
    --r;
  }

  // 相遇即为同一峰值，且峰值不能是端点（l != 0，r != n-1）
  return l == r && l != 0 && r != n - 1;
}

ValidMountainArraySolution::ValidMountainArraySolution() {
  setMetaInfo({.id = 941,
               .title = "Valid Mountain Array",
               .url = "https://leetcode.com/problems/valid-mountain-array"});
  registerStrategy({.name = "Two Pointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array"}},
                   solution1);
}

bool ValidMountainArraySolution::validMountainArray(vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_941
}  // namespace leetcode
