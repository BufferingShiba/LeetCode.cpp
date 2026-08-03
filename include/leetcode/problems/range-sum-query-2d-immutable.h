#ifndef LEETCODE_PROBLEMS_RANGE_SUM_QUERY_2D_IMMUTABLE_H_
#define LEETCODE_PROBLEMS_RANGE_SUM_QUERY_2D_IMMUTABLE_H_

#include <vector>

namespace leetcode {
namespace problem_304 {

class NumMatrix {
 public:
  explicit NumMatrix(const std::vector<std::vector<int>>& matrix);
  int sumRegion(int row1, int col1, int row2, int col2);

 private:
  std::vector<std::vector<int>> pref_;
};

}  // namespace problem_304
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RANGE_SUM_QUERY_2D_IMMUTABLE_H_
