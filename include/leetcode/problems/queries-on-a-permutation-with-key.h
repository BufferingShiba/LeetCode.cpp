#ifndef LEETCODE_PROBLEMS_QUERIES_ON_A_PERMUTATION_WITH_KEY_H__
#define LEETCODE_PROBLEMS_QUERIES_ON_A_PERMUTATION_WITH_KEY_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1409 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class QueriesOnAPermutationWithKeySolution
    : public SolutionBase<Func> {
 public:
  QueriesOnAPermutationWithKeySolution();

  std::vector<int> processQueries(std::vector<int>& queries, int m);
};

}  // namespace problem_1409
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_QUERIES_ON_A_PERMUTATION_WITH_KEY_H__
