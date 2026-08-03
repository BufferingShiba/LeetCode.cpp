#ifndef LEETCODE_PROBLEMS_CAN_PLACE_FLOWERS_H__
#define LEETCODE_PROBLEMS_CAN_PLACE_FLOWERS_H__

#include "leetcode/core.h"

#include <vector>

namespace leetcode {
namespace problem_605 {

using Func = std::function<bool(std::vector<int>&, int)>;

class CanPlaceFlowersSolution : public SolutionBase<Func> {
 public:
  CanPlaceFlowersSolution();
  bool canPlaceFlowers(std::vector<int>& flowerbed, int n);
};

}  // namespace problem_605
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CAN_PLACE_FLOWERS_H__
