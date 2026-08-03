#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/design-ride-sharing-system.h"

namespace leetcode {
namespace problem_3829 {

class DesignRideSharingSystemTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override { system_ = RideSharingSystem(); }

  RideSharingSystem system_;
};

TEST_P(DesignRideSharingSystemTest, Example1) {
  system_.addRider(3);
  system_.addDriver(2);
  system_.addRider(1);
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{2, 3}));
  system_.addDriver(5);
  system_.cancelRider(3);  // already matched, no effect
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{5, 1}));
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{-1, -1}));
}

TEST_P(DesignRideSharingSystemTest, Example2) {
  system_.addRider(8);
  system_.addDriver(8);
  system_.addDriver(6);
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{8, 8}));
  system_.addRider(2);
  system_.cancelRider(2);
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{-1, -1}));
}

TEST_P(DesignRideSharingSystemTest, SelfAuthoredNoDriverAvailable) {
  system_.addRider(10);
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{-1, -1}));
}

TEST_P(DesignRideSharingSystemTest, SelfAuthoredNoRiderAvailable) {
  system_.addDriver(10);
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{-1, -1}));
}

TEST_P(DesignRideSharingSystemTest, SelfAuthoredCancelThenMatch) {
  system_.addRider(1);
  system_.addRider(2);
  system_.cancelRider(1);
  system_.addDriver(10);
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{10, 2}));
}

TEST_P(DesignRideSharingSystemTest, SelfAuthoredCancelNonExistent) {
  system_.cancelRider(99);  // should not crash
  system_.addDriver(5);
  system_.addRider(7);
  EXPECT_EQ(system_.matchDriverWithRider(),
            (std::vector<int>{5, 7}));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, DesignRideSharingSystemTest,
    ::testing::Values(0));

}  // namespace problem_3829
}  // namespace leetcode
