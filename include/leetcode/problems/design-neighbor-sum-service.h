#ifndef LEETCODE_PROBLEMS_DESIGN_NEIGHBOR_SUM_SERVICE_H_
#define LEETCODE_PROBLEMS_DESIGN_NEIGHBOR_SUM_SERVICE_H_

#include <vector>

namespace leetcode::problem_3242 {

class NeighborSum {
 public:
  explicit NeighborSum(std::vector<std::vector<int>>& grid);
  int adjacentSum(int value);
  int diagonalSum(int value);

 private:
  std::vector<std::vector<int>> grid_;
  std::vector<std::pair<int, int>> pos_;  // value -> (row, col)
};

}  // namespace leetcode::problem_3242

#endif  // LEETCODE_PROBLEMS_DESIGN_NEIGHBOR_SUM_SERVICE_H_
