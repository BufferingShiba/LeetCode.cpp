#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_DAYS_TO_MAKE_M_BOUQUETS_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_DAYS_TO_MAKE_M_BOUQUETS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1482 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class MinimumNumberOfDaysToMakeMBouquetsSolution : public SolutionBase<Func> {
 public:
  MinimumNumberOfDaysToMakeMBouquetsSolution();

  int minDays(std::vector<int>& bloomDay, int m, int k);
};

}  // namespace problem_1482
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_DAYS_TO_MAKE_M_BOUQUETS_H__
