#ifndef LEETCODE_PROBLEMS_SHORTEST_MATCHING_SUBSTRING_H_
#define LEETCODE_PROBLEMS_SHORTEST_MATCHING_SUBSTRING_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_3455 {

using Func = std::function<int(const std::string&, const std::string&)>;

class ShortestMatchingSubstringSolution : public SolutionBase<Func> {
 public:
  ShortestMatchingSubstringSolution();
  int shortestMatchingSubstring(std::string s, std::string p);
};

}  // namespace problem_3455
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_MATCHING_SUBSTRING_H_
