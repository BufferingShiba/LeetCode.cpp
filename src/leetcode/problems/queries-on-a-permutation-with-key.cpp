#include "leetcode/problems/queries-on-a-permutation-with-key.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_1409 {

namespace {

std::vector<int> processQueriesImpl(std::vector<int>& queries, int m) {
  std::vector<int> p(m);
  for (int i = 0; i < m; ++i) p[i] = i + 1;

  std::vector<int> result;
  result.reserve(queries.size());

  for (int q : queries) {
    auto it = std::find(p.begin(), p.end(), q);
    int pos = static_cast<int>(it - p.begin());
    result.push_back(pos);
    // Move element at pos to the front.
    std::rotate(p.begin(), it, it + 1);
  }

  return result;
}

}  // namespace

QueriesOnAPermutationWithKeySolution::QueriesOnAPermutationWithKeySolution() {
  setMetaInfo({.id = 1409,
               .title = "Queries on a Permutation With Key",
               .url = "https://leetcode.com/problems/queries-on-a-permutation-with-key/"});
  registerStrategy({.name = "simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(m * q)",
                    .space_complexity = "O(m)",
                    .tags = {"Array", "Simulation"}},
                   processQueriesImpl);
}

std::vector<int> QueriesOnAPermutationWithKeySolution::processQueries(std::vector<int>& queries,
                                                                       int m) {
  return getSolution()(queries, m);
}

}  // namespace problem_1409
}  // namespace leetcode
