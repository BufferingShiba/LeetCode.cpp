#ifndef LEETCODE_PROBLEMS_638_SHOPPING_OFFERS_H__
#define LEETCODE_PROBLEMS_638_SHOPPING_OFFERS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_638 {

using Func = std::function<int(std::vector<int>&, std::vector<std::vector<int>>&, std::vector<int>&)>;

class ShoppingOffersSolution : public SolutionBase<Func> {
 public:
  ShoppingOffersSolution();
};

}  // namespace problem_638
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_638_SHOPPING_OFFERS_H__
