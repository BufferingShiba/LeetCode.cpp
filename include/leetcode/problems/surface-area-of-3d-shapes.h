#ifndef LEETCODE_PROBLEMS_SURFACE_AREA_OF_3D_SHAPES_H__
#define LEETCODE_PROBLEMS_SURFACE_AREA_OF_3D_SHAPES_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_892 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class SurfaceAreaOf3dShapesSolution : public SolutionBase<Func> {
 public:
  SurfaceAreaOf3dShapesSolution();

  int surfaceArea(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_892
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SURFACE_AREA_OF_3D_SHAPES_H__
