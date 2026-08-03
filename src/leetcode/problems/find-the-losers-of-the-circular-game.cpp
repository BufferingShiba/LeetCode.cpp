#include "leetcode/problems/find-the-losers-of-the-circular-game.h"

namespace {

std::vector<int> circularGameLosersImpl(int n, int k) {
  std::vector<bool> received(n, false);
  received[0] = true;  // 1st friend starts with the ball
  int curr = 0;
  for (int i = 1; ; ++i) {
    int next = (curr + i * k) % n;
    if (received[next]) {
      break;
    }
    received[next] = true;
    curr = next;
  }

  std::vector<int> losers;
  for (int i = 0; i < n; ++i) {
    if (!received[i]) {
      losers.push_back(i + 1);
    }
  }
  return losers;
}

}  // namespace

namespace leetcode::problem_2682 {

FindTheLosersOfTheCircularGameSolution::FindTheLosersOfTheCircularGameSolution() {
  setMetaInfo({.id = 2682, .title = "Find the Losers of the Circular Game", .url = "https://leetcode.com/problems/find-the-losers-of-the-circular-game/"});
  registerStrategy({.name = "simulation", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"Array", "Hash Table", "Simulation"}}, circularGameLosersImpl);
}

std::vector<int> FindTheLosersOfTheCircularGameSolution::circularGameLosers(int n, int k) {
  return getSolution()(n, k);
}

}  // namespace leetcode::problem_2682
