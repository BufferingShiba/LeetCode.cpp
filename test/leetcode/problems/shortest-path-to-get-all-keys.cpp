#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/shortest-path-to-get-all-keys.h"

namespace leetcode {
namespace problem_864 {

using ShortestPathToGetAllKeysTestBase = ::testing::TestWithParam<std::string>;

class ShortestPathToGetAllKeysTest : public ShortestPathToGetAllKeysTestBase {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  ShortestPathToGetAllKeysSolution solution_;
};

TEST_P(ShortestPathToGetAllKeysTest, Example1) {
  std::vector<std::string> grid = {"@.a..", "###.#", "b.A.B"};
  EXPECT_EQ(8, solution_.shortestPathAllKeys(grid));
}

TEST_P(ShortestPathToGetAllKeysTest, Example2) {
  std::vector<std::string> grid = {"@..aA", "..B#.", "....b"};
  EXPECT_EQ(6, solution_.shortestPathAllKeys(grid));
}

TEST_P(ShortestPathToGetAllKeysTest, Example3) {
  std::vector<std::string> grid = {"@Aa"};
  EXPECT_EQ(-1, solution_.shortestPathAllKeys(grid));
}

TEST_P(ShortestPathToGetAllKeysTest, DirectKeyNoLock) {
  std::vector<std::string> grid = {"@..a"};
  EXPECT_EQ(3, solution_.shortestPathAllKeys(grid));
}

TEST_P(ShortestPathToGetAllKeysTest, CollectTwoKeysAdjacent) {
  // start (0,0); keys 'a' (0,2) and 'b' (1,2); no locks.
  // path: (0,0)->(0,1)->(0,2)[a]->(1,2)[b] = 3 moves.
  std::vector<std::string> grid = {"@.a", "..b"};
  EXPECT_EQ(3, solution_.shortestPathAllKeys(grid));
}

INSTANTIATE_TEST_SUITE_P(
    ShortestPathToGetAllKeysTests, ShortestPathToGetAllKeysTest,
    ::testing::ValuesIn(ShortestPathToGetAllKeysSolution().getStrategyNames()));

}  // namespace problem_864
}  // namespace leetcode
