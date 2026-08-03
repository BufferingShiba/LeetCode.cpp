#ifndef LEETCODE_PROBLEMS_TAKE_GIFTS_FROM_THE_RICHEST_PILE_H__
#define LEETCODE_PROBLEMS_TAKE_GIFTS_FROM_THE_RICHEST_PILE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2558 {

using Func = std::function<long long(std::vector<int>&, int)>;

class TakeGiftsFromTheRichestPileSolution
    : public SolutionBase<Func> {
 public:
  TakeGiftsFromTheRichestPileSolution();

  long long pickGifts(std::vector<int>& gifts,
                      int k);

 private:
  static long long pickGiftsImpl(std::vector<int>& gifts, int k);
};

}  // namespace problem_2558
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TAKE_GIFTS_FROM_THE_RICHEST_PILE_H__
