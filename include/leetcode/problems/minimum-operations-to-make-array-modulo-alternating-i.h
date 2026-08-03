#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_MODULO_ALTERNATING_I_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_MODULO_ALTERNATING_I_H__

#include "leetcode/core.h"

#include <cstdint>
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3937 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumOperationsToMakeArrayModuloAlternatingISolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToMakeArrayModuloAlternatingISolution() {
    setMetaInfo({
        .id = 3937,
        .title = "Minimum Operations to Make Array Modulo Alternating I",
        .url =
            "https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/",
    });

    registerStrategy(
        {
            .name = "EnumerateXY",
            .expected = "Accepted",
            .time_complexity = "O(k^2 * n)",
            .space_complexity = "O(1)",
            .tags = {"Array", "Enumeration"},
            .notes =
                "枚举偶数目标 x 与奇数目标 y（x!=y），对每个位置计算调整为最近模 k == m 的代价。",
        },
        minOperationsEnumerateXY);
  }

  int minOperations(std::vector<int>& nums, int k) {
    return getSolution()(nums, k);
  }

 private:
  static int minOperationsEnumerateXY(std::vector<int>& nums, int k);
};

}  // namespace problem_3937
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_MODULO_ALTERNATING_I_H__
