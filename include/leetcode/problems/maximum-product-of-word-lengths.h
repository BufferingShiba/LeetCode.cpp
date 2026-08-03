#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_WORD_LENGTHS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_WORD_LENGTHS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_318 {

using Func = std::function<int(std::vector<std::string>&)>;

class MaximumProductOfWordLengthsSolution : public SolutionBase<Func> {
 public:
  MaximumProductOfWordLengthsSolution();

  int maxProduct(std::vector<std::string>& words) {
    return getSolution()(words);
  }
};

}  // namespace problem_318
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRODUCT_OF_WORD_LENGTHS_H__
