#ifndef LEETCODE_PROBLEMS_REFORMAT_PHONE_NUMBER_H__
#define LEETCODE_PROBLEMS_REFORMAT_PHONE_NUMBER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1694 {

using Func = std::function<std::string(const std::string&)>;

class ReformatPhoneNumberSolution
    : public SolutionBase<Func> {
 public:
  ReformatPhoneNumberSolution();

  std::string reformatNumber(const std::string& number);
};

}  // namespace problem_1694
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REFORMAT_PHONE_NUMBER_H__
