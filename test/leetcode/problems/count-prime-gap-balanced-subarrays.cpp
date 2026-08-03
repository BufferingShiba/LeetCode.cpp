#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-prime-gap-balanced-subarrays.h"

namespace leetcode {
namespace problem_3589 {
namespace {

class CountPrimeGapBalancedSubarraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountPrimeGapBalancedSubarraysSolution solution_;
};

TEST_P(CountPrimeGapBalancedSubarraysTest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  int k = 1;
  EXPECT_EQ(solution_.primeSubarray(nums, k), 2);
}

TEST_P(CountPrimeGapBalancedSubarraysTest, Example2) {
  std::vector<int> nums = {2, 3, 5, 7};
  int k = 3;
  EXPECT_EQ(solution_.primeSubarray(nums, k), 4);
}

TEST_P(CountPrimeGapBalancedSubarraysTest, SelfAuthoredSinglePrime) {
  std::vector<int> nums = {3};
  int k = 0;
  EXPECT_EQ(solution_.primeSubarray(nums, k), 0);
}

TEST_P(CountPrimeGapBalancedSubarraysTest, SelfAuthoredNoPrime) {
  std::vector<int> nums = {1, 4, 6, 8};
  int k = 5;
  EXPECT_EQ(solution_.primeSubarray(nums, k), 0);
}

TEST_P(CountPrimeGapBalancedSubarraysTest, SelfAuthoredZeroGap) {
  std::vector<int> nums = {2, 1, 2};
  int k = 0;
  // Subarrays containing >=2 primes where max-min <= 0 means all equal.
  // All primes are 2 here.
  EXPECT_EQ(solution_.primeSubarray(nums, k), 1);
}

TEST_P(CountPrimeGapBalancedSubarraysTest, SelfAuthoredLongArrayWithGap) {
  std::vector<int> nums = {3, 10, 5, 10, 7};
  int k = 2;
  // primes at idx0(3), idx2(5), idx4(7). Windows (a<b, diff<=2):
  // [0,2] diff2: leftW0=1,right2=(4-2)=2 => 1*2=2
  // [2,4] diff2: leftW2=(2-0)=2,right4=(5-4)=1 => 2*1=2
  // [0,4] diff4>2 no.
  // also [0,4]... total 4
  EXPECT_EQ(solution_.primeSubarray(nums, k), 4);
}

TEST_P(CountPrimeGapBalancedSubarraysTest, ValuesNeedWholeWindowRange) {
  std::vector<int> nums = {42979, 42976, 16529};
  int k = 15247;
  // 42979 and 16529 are prime, but their difference exceeds k.  Checking
  // only the current endpoint against the first prime incorrectly counts 1.
  EXPECT_EQ(solution_.primeSubarray(nums, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountPrimeGapBalancedSubarraysTestSuite,
    CountPrimeGapBalancedSubarraysTest,
    ::testing::ValuesIn(
        CountPrimeGapBalancedSubarraysSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3589
}  // namespace leetcode
