#ifndef LEETCODE_PROBLEMS_HEXADECIMAL_AND_HEXATRIGESIMAL_CONVERSION_H__
#define LEETCODE_PROBLEMS_HEXADECIMAL_AND_HEXATRIGESIMAL_CONVERSION_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3602 {

using Func = std::function<std::string(int)>;

class HexadecimalAndHexatrigesimalConversionSolution
    : public SolutionBase<Func> {
 public:
  HexadecimalAndHexatrigesimalConversionSolution();

  std::string concatHex36(int n);
};

}  // namespace problem_3602
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_HEXADECIMAL_AND_HEXATRIGESIMAL_CONVERSION_H__
