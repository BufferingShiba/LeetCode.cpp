#include "leetcode/problems/arithmetic-slices.h"
#include <vector>

namespace leetcode {
namespace problem_413 {

namespace {

int numberOfArithmeticSlicesImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n < 3) {
    return 0;
  }
  int total = 0;
  int cur = 0;  // 以当前索引结尾的、长度 >= 3 的等差子数组个数
  for (int i = 2; i < n; ++i) {
    if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
      ++cur;
    } else {
      cur = 0;
    }
    total += cur;
  }
  return total;
}

}  // namespace

ArithmeticSlicesSolution::ArithmeticSlicesSolution() {
  setMetaInfo({.id = 413,
               .title = "Arithmetic Slices",
               .url = "https://leetcode.com/problems/arithmetic-slices/"});
  registerStrategy({"LinearDP", "Accepted", "O(n)", "O(1)", {"Array", "Dynamic Programming", "Sliding Window"}},
                    numberOfArithmeticSlicesImpl);
}

int ArithmeticSlicesSolution::numberOfArithmeticSlices(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_413
}  // namespace leetcode
