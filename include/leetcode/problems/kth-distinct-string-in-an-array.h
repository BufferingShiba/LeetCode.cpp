#ifndef LEETCODE_PROBLEMS_KTH_DISTINCT_STRING_IN_AN_ARRAY_H
#define LEETCODE_PROBLEMS_KTH_DISTINCT_STRING_IN_AN_ARRAY_H

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2053 {

using Func = std::function<std::string(std::vector<std::string>&, int)>;

class KthDistinctStringInAnArraySolution : public SolutionBase<Func> {
 public:
  KthDistinctStringInAnArraySolution();

  // Original problem method.
  std::string kthDistinct(std::vector<std::string>& arr, int k);
};

}  // namespace problem_2053
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_KTH_DISTINCT_STRING_IN_AN_ARRAY_H
