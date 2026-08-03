#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/merge-triplets-to-form-target-triplet.h"

namespace leetcode {
namespace problem_1899 {

namespace {

bool runMergeTriplets(const std::string& strategy, std::vector<std::vector<int>>& triplets,
                      std::vector<int>& target) {
  MergeTripletsToFormTargetTriplet solution;
  solution.setStrategy(strategy);
  return solution.mergeTriplets(triplets, target);
}

}  // namespace

class MergeTripletsToFormTargetTripletTest : public ::testing::TestWithParam<std::string> {};

TEST_P(MergeTripletsToFormTargetTripletTest, Example1) {
  std::vector<std::vector<int>> triplets = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
  std::vector<int> target = {2, 7, 5};
  EXPECT_TRUE(runMergeTriplets(GetParam(), triplets, target));
}

TEST_P(MergeTripletsToFormTargetTripletTest, Example2) {
  std::vector<std::vector<int>> triplets = {{3, 4, 5}, {4, 5, 6}};
  std::vector<int> target = {3, 2, 5};
  EXPECT_FALSE(runMergeTriplets(GetParam(), triplets, target));
}

TEST_P(MergeTripletsToFormTargetTripletTest, Example3) {
  std::vector<std::vector<int>> triplets = {{2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3}};
  std::vector<int> target = {5, 5, 5};
  EXPECT_TRUE(runMergeTriplets(GetParam(), triplets, target));
}

TEST_P(MergeTripletsToFormTargetTripletTest, SelfAuthoredSingleElementExactMatch) {
  std::vector<std::vector<int>> triplets = {{7, 7, 7}};
  std::vector<int> target = {7, 7, 7};
  EXPECT_TRUE(runMergeTriplets(GetParam(), triplets, target));
}

TEST_P(MergeTripletsToFormTargetTripletTest, SelfAuthoredOverlappingFeasibleTriplets) {
  std::vector<std::vector<int>> triplets = {{1, 2, 3}, {3, 2, 1}, {2, 1, 2}};
  std::vector<int> target = {3, 2, 3};
  EXPECT_TRUE(runMergeTriplets(GetParam(), triplets, target));
}

TEST_P(MergeTripletsToFormTargetTripletTest, SelfAuthoredMissingValueImpossible) {
  std::vector<std::vector<int>> triplets = {{3, 4, 5}, {4, 5, 6}};
  std::vector<int> target = {3, 2, 5};
  EXPECT_FALSE(runMergeTriplets(GetParam(), triplets, target));
}

INSTANTIATE_TEST_SUITE_P(
    MergeTripletsToFormTargetTripletTests, MergeTripletsToFormTargetTripletTest,
    ::testing::ValuesIn(MergeTripletsToFormTargetTriplet().getStrategyNames()));

}  // namespace problem_1899
}  // namespace leetcode
