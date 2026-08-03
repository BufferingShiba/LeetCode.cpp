#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SELECT_BUILDINGS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SELECT_BUILDINGS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2222 {

using Func = std::function<long long(std::string)>;

class NumberOfWaysToSelectBuildingsSolution
    : public SolutionBase<Func> {
 public:
  NumberOfWaysToSelectBuildingsSolution();

  long long numberOfWays(std::string s);
};

}  // namespace problem_2222
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SELECT_BUILDINGS_H__
