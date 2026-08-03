#include "leetcode/problems/detect-squares.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2013 {

TEST(LeetCode, DetectSquaresTest) {
  DetectSquares detectSquares;

  detectSquares.add({3, 10});
  detectSquares.add({11, 2});
  detectSquares.add({3, 2});

  EXPECT_EQ(1, detectSquares.count({11, 10}));
  EXPECT_EQ(0, detectSquares.count({14, 8}));

  detectSquares.add({11, 2});  // duplicate points are allowed

  EXPECT_EQ(2, detectSquares.count({11, 10}));
}

}  // namespace problem_2013
}  // namespace leetcode
