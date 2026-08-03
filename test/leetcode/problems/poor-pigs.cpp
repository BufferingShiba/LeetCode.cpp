#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/poor-pigs.h"

namespace leetcode::problem_458 {
namespace {

using TestParam = std::tuple<int, int, int, int>;

}  // namespace

class PoorPigsTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    void run(int buckets, int minutesToDie, int minutesToTest, int expected) {
        EXPECT_EQ(solution.poorPigs(buckets, minutesToDie, minutesToTest), expected);
    }

    PoorPigsSolution solution;
};

TEST_P(PoorPigsTest, Example1) {
    run(4, 15, 15, 2);
}

TEST_P(PoorPigsTest, Example2) {
    run(4, 15, 30, 2);
}

TEST_P(PoorPigsTest, SingleBucket) {
    run(1, 15, 15, 0);
}

TEST_P(PoorPigsTest, ManyBuckets) {
    // minutesToTest/minutesToDie + 1 = 1 + 1 = 2 states per pig.
    // 2^9 = 512 < 1000, 2^10 = 1024 >= 1000 => 10 pigs.
    run(1000, 100, 100, 10);
}

TEST_P(PoorPigsTest, ManyBucketsMoreTime) {
    // states = 100/15 + 1 = 6 + 1 = 7.
    // 7^3 = 343 < 1000, 7^4 = 2401 >= 1000 => 4 pigs.
    run(1000, 15, 100, 4);
}

INSTANTIATE_TEST_SUITE_P(
    PoorPigsStrategies,
    PoorPigsTest,
    ::testing::ValuesIn(PoorPigsSolution().getStrategyNames()));

}  // namespace leetcode::problem_458
