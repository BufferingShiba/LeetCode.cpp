#include "leetcode/problems/poor-pigs.h"

namespace leetcode::problem_458 {

namespace {

int poorPigsImpl(int buckets, int minutesToDie, int minutesToTest) {
    const int states = minutesToTest / minutesToDie + 1;
    int pigs = 0;
    long long covered = 1;
    while (covered < buckets) {
        covered *= states;
        ++pigs;
    }
    return pigs;
}

}  // namespace

PoorPigsSolution::PoorPigsSolution() {
    setMetaInfo({.id = 458,
                 .title = "Poor Pigs",
                 .url =
                     "https://leetcode.com/problems/poor-pigs/"});

    registerStrategy(
        {.name = "combinatorics",
         .expected = "Accepted",
         .time_complexity = "O(log buckets)",
         .space_complexity = "O(1)",
         .tags = {"Math", "Combinatorics"}},
        [](int buckets, int minutesToDie, int minutesToTest) {
            return poorPigsImpl(buckets, minutesToDie, minutesToTest);
        });
}

int PoorPigsSolution::poorPigs(int buckets, int minutesToDie,
                               int minutesToTest) {
    return getSolution()(buckets, minutesToDie, minutesToTest);
}

}  // namespace leetcode::problem_458
