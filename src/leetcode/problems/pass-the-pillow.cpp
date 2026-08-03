#include "leetcode/problems/pass-the-pillow.h"

namespace leetcode {
namespace problem_2582 {

namespace {

int passThePillowImpl(int n, int time) {
  int cycle = 2 * (n - 1);
  int pos = time % cycle;
  if (pos < n) {
    return pos + 1;
  }
  return 2 * n - 1 - pos;
}

}  // namespace

PassThePillowSolution::PassThePillowSolution() {
  setMetaInfo({.id = 2582,
               .title = "Pass the Pillow",
               .url = "https://leetcode.com/problems/pass-the-pillow/"});
  registerStrategy({.name = "Math",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Simulation"}},
                   passThePillowImpl);
}

int PassThePillowSolution::passThePillow(int n, int time) {
  return getSolution()(n, time);
}

}  // namespace problem_2582
}  // namespace leetcode
