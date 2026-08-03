#ifndef LEETCODE_PROBLEMS_FRUIT_INTO_BASKETS_H__
#define LEETCODE_PROBLEMS_FRUIT_INTO_BASKETS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_904 {

using Func = std::function<int(std::vector<int>&)>;

class FruitIntoBasketsSolution : public SolutionBase<Func> {
 public:
  FruitIntoBasketsSolution();

  int totalFruit(std::vector<int>& fruits);
};

}  // namespace problem_904
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FRUIT_INTO_BASKETS_H__
