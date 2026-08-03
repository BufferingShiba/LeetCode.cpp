#ifndef LEETCODE_PROBLEMS_JEWELS_AND_STONES_H__
#define LEETCODE_PROBLEMS_JEWELS_AND_STONES_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_771 {

using Func = std::function<int(std::string, std::string)>;

class JewelsAndStonesSolution : public SolutionBase<Func> {
 public:
  JewelsAndStonesSolution();

  int numJewelsInStones(std::string jewels, std::string stones);
};

}  // namespace problem_771
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_JEWELS_AND_STONES_H__
