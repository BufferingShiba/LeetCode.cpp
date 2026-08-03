#include "leetcode/problems/stone-removal-game.h"

namespace leetcode {
namespace problem_3360 {

namespace {

bool canAliceWinImpl(int n) {
  int need = 10;
  bool aliceTurn = true;

  while (n >= need) {
    n -= need;
    --need;
    aliceTurn = !aliceTurn;
  }

  return !aliceTurn;
}

}  // namespace

StoneRemovalGameSolution::StoneRemovalGameSolution() {
  setMetaInfo(3360, "Stone Removal Game",
              "https://leetcode.com/problems/stone-removal-game/");

  StrategyMetadata metadata;
  metadata.name = "Simulation";
  metadata.expected = "Accepted";
  metadata.time_complexity = "O(1)";
  metadata.space_complexity = "O(1)";
  metadata.tags = {"Math", "Simulation"};
  registerStrategy(metadata, canAliceWinImpl);

  setDefaultStrategy();
}

bool StoneRemovalGameSolution::canAliceWin(int n) {
  return getSolution()(n);
}

}  // namespace problem_3360
}  // namespace leetcode
