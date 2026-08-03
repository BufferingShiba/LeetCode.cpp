#include <gtest/gtest.h>

#include "leetcode/problems/minimized-maximum-of-products-distributed-to-any-store.h"

namespace leetcode {
namespace problem_2064 {

class MinimizedMaximumOfProductsDistributedToAnyStoreTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimizedMaximumOfProductsDistributedToAnyStoreSolution solution_;
};

TEST_P(MinimizedMaximumOfProductsDistributedToAnyStoreTest, Example1) {
  int n = 6;
  std::vector<int> quantities = {11, 6};
  EXPECT_EQ(solution_.minimizedMaximum(n, quantities), 3);
}

TEST_P(MinimizedMaximumOfProductsDistributedToAnyStoreTest, Example2) {
  int n = 7;
  std::vector<int> quantities = {15, 10, 10};
  EXPECT_EQ(solution_.minimizedMaximum(n, quantities), 5);
}

TEST_P(MinimizedMaximumOfProductsDistributedToAnyStoreTest, Example3) {
  int n = 1;
  std::vector<int> quantities = {100000};
  EXPECT_EQ(solution_.minimizedMaximum(n, quantities), 100000);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimizedMaximumOfProductsDistributedToAnyStoreTest,
    testing::ValuesIn(
        MinimizedMaximumOfProductsDistributedToAnyStoreSolution()
            .getStrategyNames()));

}  // namespace problem_2064
}  // namespace leetcode
