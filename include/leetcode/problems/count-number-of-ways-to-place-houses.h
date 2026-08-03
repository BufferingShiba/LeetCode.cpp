#include "leetcode/core.h"

namespace leetcode {
namespace problem_2320 {

using Func = std::function<int(int)>;

class CountNumberOfWaysToPlaceHousesSolution : public SolutionBase<Func> {
 public:
  //! 2320. Count Number of Ways to Place Houses
  //! https://leetcode.com/problems/count-number-of-ways-to-place-houses/
  int countHousePlacements(int n);

  CountNumberOfWaysToPlaceHousesSolution();
};

}  // namespace problem_2320
}  // namespace leetcode
