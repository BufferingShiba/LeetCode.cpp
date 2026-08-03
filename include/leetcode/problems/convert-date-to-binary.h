#ifndef LEETCODE_PROBLEMS_CONVERT_DATE_TO_BINARY_H__
#define LEETCODE_PROBLEMS_CONVERT_DATE_TO_BINARY_H__

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3280 {

using Func = std::function<std::string(std::string)>;

class ConvertDateToBinarySolution : public SolutionBase<Func> {
 public:
  ConvertDateToBinarySolution();

  std::string convertDateToBinary(std::string date);
};

}  // namespace problem_3280
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONVERT_DATE_TO_BINARY_H__
