#ifndef LEETCODE_PROBLEMS_FIND_THE_DEGREE_OF_EACH_VERTEX_H__
#define LEETCODE_PROBLEMS_FIND_THE_DEGREE_OF_EACH_VERTEX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3898 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class FindTheDegreeOfEachVertexSolution
    : public SolutionBase<Func> {
 public:
  FindTheDegreeOfEachVertexSolution();

  std::vector<int> findDegrees(std::vector<std::vector<int>>& matrix);
};

}  // namespace problem_3898
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_DEGREE_OF_EACH_VERTEX_H__
