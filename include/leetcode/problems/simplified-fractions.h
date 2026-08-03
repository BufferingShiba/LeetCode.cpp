#ifndef LEETCODE_PROBLEMS_SIMPLIFIED_FRACTIONS_H__
#define LEETCODE_PROBLEMS_SIMPLIFIED_FRACTIONS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1447 {

using Func = std::function<std::vector<std::string>(int)>;

class SimplifiedFractionsSolution : public SolutionBase<Func> {
 public:
  SimplifiedFractionsSolution();

  std::vector<std::string> simplifiedFractions(int n) {
    return getSolution()(n);
  }
};

}  // namespace problem_1447
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SIMPLIFIED_FRACTIONS_H__
