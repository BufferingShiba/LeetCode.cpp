#ifndef LEETCODE_PROBLEMS_NUMBER_OF_EVEN_AND_ODD_BITS_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_EVEN_AND_ODD_BITS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2595 {

using Func = std::function<std::vector<int>(int)>;

class NumberOfEvenAndOddBitsSolution : public SolutionBase<Func> {
 public:
  NumberOfEvenAndOddBitsSolution();

  std::vector<int> evenOddBit(int n) {
    return getSolution()(n);
  }
};

}  // namespace problem_2595
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_EVEN_AND_ODD_BITS_H_
