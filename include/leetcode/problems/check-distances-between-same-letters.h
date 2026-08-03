#ifndef LEETCODE_PROBLEMS_CHECK_DISTANCES_BETWEEN_SAME_LETTERS_H__
#define LEETCODE_PROBLEMS_CHECK_DISTANCES_BETWEEN_SAME_LETTERS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2399 {

using Func = std::function<bool(std::string, std::vector<int>&)>;

class CheckDistancesBetweenSameLettersSolution
    : public SolutionBase<Func> {
 public:
  CheckDistancesBetweenSameLettersSolution();

  bool checkDistances(std::string s, std::vector<int>& distance);
};

}  // namespace problem_2399
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_DISTANCES_BETWEEN_SAME_LETTERS_H__
