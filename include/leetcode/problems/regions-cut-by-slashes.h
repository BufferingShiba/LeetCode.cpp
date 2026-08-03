#ifndef LEETCODE_PROBLEMS_REGIONS_CUT_BY_SLASHES_H__
#define LEETCODE_PROBLEMS_REGIONS_CUT_BY_SLASHES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_959 {

using Func = std::function<int(std::vector<std::string>&)>;

class RegionsCutBySlashesSolution : public SolutionBase<Func> {
 public:
  RegionsCutBySlashesSolution();

  int regionsBySlashes(std::vector<std::string>& grid);
};

}  // namespace problem_959
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REGIONS_CUT_BY_SLASHES_H__
