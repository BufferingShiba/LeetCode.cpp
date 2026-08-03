#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/asteroid-collision.h"

namespace leetcode {
namespace problem_735 {

class AsteroidCollisionTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AsteroidCollisionSolution solution;
};

TEST_P(AsteroidCollisionTest, Example1) {
  std::vector<int> asteroids = {5, 10, -5};
  std::vector<int> expected = {5, 10};
  EXPECT_EQ(expected, solution.asteroidCollision(asteroids));
}

TEST_P(AsteroidCollisionTest, Example2) {
  std::vector<int> asteroids = {8, -8};
  std::vector<int> expected = {};
  EXPECT_EQ(expected, solution.asteroidCollision(asteroids));
}

TEST_P(AsteroidCollisionTest, Example3) {
  std::vector<int> asteroids = {10, 2, -5};
  std::vector<int> expected = {10};
  EXPECT_EQ(expected, solution.asteroidCollision(asteroids));
}

TEST_P(AsteroidCollisionTest, Example4) {
  std::vector<int> asteroids = {3, 5, -6, 2, -1, 4};
  std::vector<int> expected = {-6, 2, 4};
  EXPECT_EQ(expected, solution.asteroidCollision(asteroids));
}

TEST_P(AsteroidCollisionTest, SelfAuthoredAllSameDirection) {
  std::vector<int> asteroids = {3, 7, 1, 4};
  std::vector<int> expected = {3, 7, 1, 4};
  EXPECT_EQ(expected, solution.asteroidCollision(asteroids));
}

TEST_P(AsteroidCollisionTest, SelfAuthoredMultipleCollisions) {
  std::vector<int> asteroids = {-2, -1, 1, 2};
  std::vector<int> expected = {-2, -1, 1, 2};
  EXPECT_EQ(expected, solution.asteroidCollision(asteroids));
}

TEST_P(AsteroidCollisionTest, SelfAuthoredEqualSizeExplode) {
  std::vector<int> asteroids = {1, -1};
  std::vector<int> expected = {};
  EXPECT_EQ(expected, solution.asteroidCollision(asteroids));
}

INSTANTIATE_TEST_SUITE_P(
    AsteroidCollisionTestSuite, AsteroidCollisionTest,
    ::testing::ValuesIn(AsteroidCollisionSolution().getStrategyNames()));

}  // namespace problem_735
}  // namespace leetcode
