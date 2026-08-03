#ifndef LEETCODE_PROBLEMS_DISTRIBUTE_CANDIES_AMONG_CHILDREN_I_H__
#define LEETCODE_PROBLEMS_DISTRIBUTE_CANDIES_AMONG_CHILDREN_I_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2928 {

using Func = std::function<int(int, int)>;

class DistributeCandiesAmongChildrenISolution : public SolutionBase<Func> {
 public:
  DistributeCandiesAmongChildrenISolution() {
    setMetaInfo({.id = 2928,
                 .title = "Distribute Candies Among Children I",
                 .url = "https://leetcode.com/problems/distribute-candies-among-children-i/"});

    registerStrategy(
        {.name = "brute-force",
         .expected = "Accepted",
         .time_complexity = "O(n * limit)",
         .space_complexity = "O(1)",
         .tags = {"Math", "Enumeration"},
         .notes = "Enumerate candies for first two children, derive third."},
        distributeCandiesImpl);
  }

  int distributeCandies(int n, int limit) { return getSolution()(n, limit); }

 private:
  static int distributeCandiesImpl(int n, int limit) {
    int count = 0;
    for (int i = 0; i <= limit && i <= n; ++i) {
      for (int j = 0; j <= limit && j <= n - i; ++j) {
        int k = n - i - j;
        if (k <= limit) {
          ++count;
        }
      }
    }
    return count;
  }
};

}  // namespace problem_2928
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DISTRIBUTE_CANDIES_AMONG_CHILDREN_I_H__
