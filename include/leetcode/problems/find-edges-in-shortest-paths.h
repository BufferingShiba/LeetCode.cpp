#ifndef LEETCODE_PROBLEM_FIND_EDGES_IN_SHORTEST_PATHS_H
#define LEETCODE_PROBLEM_FIND_EDGES_IN_SHORTEST_PATHS_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3123 {

using Func = std::function<std::vector<bool>(int, std::vector<std::vector<int>>&)>;

class FindEdgesInShortestPathsSolution : public SolutionBase<Func> {
 public:
  FindEdgesInShortestPathsSolution();
  std::vector<bool> findAnswer(int n, std::vector<std::vector<int>>& edges);
};

}  // namespace problem_3123
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_FIND_EDGES_IN_SHORTEST_PATHS_H
