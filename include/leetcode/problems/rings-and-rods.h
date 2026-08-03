#ifndef LEETCODE_PROBLEMS_RINGS_AND_RODS_H__
#define LEETCODE_PROBLEMS_RINGS_AND_RODS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2103 {

using Func = std::function<int(std::string)>;

class RingsAndRodsSolution : public SolutionBase<Func> {
 public:
  RingsAndRodsSolution();

  int countPoints(std::string rings);
};

}  // namespace problem_2103
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RINGS_AND_RODS_H__
