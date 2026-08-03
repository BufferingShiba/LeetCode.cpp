#ifndef LEETCODE_PROBLEM_3606_COUPON_CODE_VALIDATOR_H__
#define LEETCODE_PROBLEM_3606_COUPON_CODE_VALIDATOR_H__

#include "leetcode/core.h"

namespace leetcode::problem_3606 {

using Func = std::function<std::vector<std::string>(
    std::vector<std::string>&, std::vector<std::string>&, std::vector<bool>&)>;

class CouponCodeValidatorSolution : public SolutionBase<Func> {
 public:
  CouponCodeValidatorSolution();

  std::vector<std::string> validateCoupons(std::vector<std::string>& code,
                                           std::vector<std::string>& businessLine,
                                           std::vector<bool>& isActive);
};

}  // namespace leetcode::problem_3606

#endif  // LEETCODE_PROBLEM_3606_COUPON_CODE_VALIDATOR_H__
