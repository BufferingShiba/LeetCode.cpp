#ifndef LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_OPERATIONS_WITH_CONSTRAINT_H_
#define LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_OPERATIONS_WITH_CONSTRAINT_H_

#include "leetcode/core.h"

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3106 {

using Func = std::function<std::string(std::string, int)>;

class LexicographicallySmallestStringAfterOperationsWithConstraintSolution
    : public SolutionBase<Func> {
 public:
  LexicographicallySmallestStringAfterOperationsWithConstraintSolution() {
    setMetaInfo({
        .id = 3106,
        .title = "Lexicographically Smallest String After Operations With Constraint",
        .url =
            "https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/",
    });
    registerStrategy(
        {
            .name = "Greedy",
            .expected = "Accepted",
            .time_complexity = "O(n)",
            .space_complexity = "O(1)",
            .tags = {"String", "Greedy"},
        },
        getSmallestStringGreedy);
  }

  std::string getSmallestString(std::string s, int k) {
    return getSolution()(std::move(s), k);
  }

 private:
  static std::string getSmallestStringGreedy(std::string s, int k);
};

}  // namespace problem_3106
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LEXICOGRAPHICALLY_SMALLEST_STRING_AFTER_OPERATIONS_WITH_CONSTRAINT_H_
