#ifndef LEETCODE_PROBLEMS_PROJECTION_AREA_OF_3D_SHAPES_H_
#define LEETCODE_PROBLEMS_PROJECTION_AREA_OF_3D_SHAPES_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_883 {

class ProjectionAreaOf3dShapesSolution
    : public SolutionBase<std::function<int(std::vector<std::vector<int>>&)>> {
 public:
  ProjectionAreaOf3dShapesSolution();
  int projectionArea(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_883

#endif  // LEETCODE_PROBLEMS_PROJECTION_AREA_OF_3D_SHAPES_H_
