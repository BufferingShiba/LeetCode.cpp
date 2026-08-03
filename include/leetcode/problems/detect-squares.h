#include "leetcode/core.h"

#include <unordered_map>

namespace leetcode {
namespace problem_2013 {

//! 2013. Detect Squares
//! https://leetcode.com/problems/detect-squares/
class DetectSquares {
 public:
  DetectSquares();
  void add(vector<int> point);
  int count(vector<int> point);

 private:
  // points[x][y] = number of stored points at coordinate (x, y)
  unordered_map<int, unordered_map<int, int>> points;
};

}  // namespace problem_2013
}  // namespace leetcode
