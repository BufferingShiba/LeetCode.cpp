#include "leetcode/problems/incremental-memory-leak.h"

namespace leetcode {
namespace problem_1860 {

static vector<int> solution1(int memory1, int memory2) {
  int time = 1;
  while (true) {
    // Pick the stick with more available memory (stick 1 on tie).
    if (memory1 >= memory2) {
      if (memory1 < time) break;  // not enough memory on the chosen stick
      memory1 -= time;
    } else {
      if (memory2 < time) break;
      memory2 -= time;
    }
    ++time;
  }
  return {time, memory1, memory2};
}

IncrementalMemoryLeakSolution::IncrementalMemoryLeakSolution() {
  setMetaInfo({
      .id = 1860,
      .title = "Incremental Memory Leak",
      .url = "https://leetcode.com/problems/incremental-memory-leak"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

vector<int> IncrementalMemoryLeakSolution::memLeak(int memory1, int memory2) {
  return getSolution()(memory1, memory2);
}

}  // namespace problem_1860
}  // namespace leetcode
