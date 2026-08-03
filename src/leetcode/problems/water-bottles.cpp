#include "leetcode/problems/water-bottles.h"

namespace leetcode {
namespace problem_1518 {

namespace {

int numWaterBottlesImpl(int numBottles, int numExchange) {
  int drunk = 0;
  int full = numBottles;
  int empty = 0;

  while (full > 0) {
    // drink all full bottles
    drunk += full;
    empty += full;
    full = 0;

    // exchange empty bottles for full ones
    full = empty / numExchange;
    empty = empty % numExchange;
  }

  return drunk;
}

}  // namespace

WaterBottlesSolution::WaterBottlesSolution() {
  setMetaInfo({.id = 1518, .title = "Water Bottles", .url = "https://leetcode.com/problems/water-bottles/"});
  registerStrategy({.name = "Simulation",
                     .expected = "Accepted",
                     .time_complexity = "O(log n)",
                     .space_complexity = "O(1)",
                     .tags = {"Math", "Simulation"}},
                   numWaterBottlesImpl);
  setDefaultStrategy();
}

int WaterBottlesSolution::numWaterBottles(int numBottles, int numExchange) {
  return getSolution()(numBottles, numExchange);
}

}  // namespace problem_1518
}  // namespace leetcode
