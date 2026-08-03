#ifndef LEETCODE_PROBLEMS_MAXIMIZE_AMOUNT_AFTER_TWO_DAYS_OF_CONVERSIONS_H__
#define LEETCODE_PROBLEMS_MAXIMIZE_AMOUNT_AFTER_TWO_DAYS_OF_CONVERSIONS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3387 {

using Func = std::function<double(
    std::string, std::vector<std::vector<std::string>>&, std::vector<double>&,
    std::vector<std::vector<std::string>>&, std::vector<double>&)>;

class MaximizeAmountAfterTwoDaysOfConversions
    : public SolutionBase<Func> {
 public:
  MaximizeAmountAfterTwoDaysOfConversions();

  double maxAmount(std::string initialCurrency,
                   std::vector<std::vector<std::string>>& pairs1,
                   std::vector<double>& rates1,
                   std::vector<std::vector<std::string>>& pairs2,
                   std::vector<double>& rates2);
};

using MaximizeAmountAfterTwoDaysOfConversionsSolution =
    MaximizeAmountAfterTwoDaysOfConversions;

}  // namespace problem_3387
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_AMOUNT_AFTER_TWO_DAYS_OF_CONVERSIONS_H__
