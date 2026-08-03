#ifndef LEETCODE_PROBLEMS_SHORTEST_PATH_TO_GET_ALL_KEYS_H__
#define LEETCODE_PROBLEMS_SHORTEST_PATH_TO_GET_ALL_KEYS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_864 {

using Func = std::function<int(std::vector<std::string>&)>;

class ShortestPathToGetAllKeysSolution : public SolutionBase<Func> {
 public:
  ShortestPathToGetAllKeysSolution();

  int shortestPathAllKeys(std::vector<std::string>& grid);
};

}  // namespace problem_864
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_PATH_TO_GET_ALL_KEYS_H__
