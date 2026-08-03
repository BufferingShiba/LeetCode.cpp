#include "leetcode/problems/count-square-sum-triples.h"

#include <vector>

namespace leetcode::problem_1925 {

static int countTriplesImpl(int n) {
  int maxSquare = n * n;
  std::vector<bool> isSquare(maxSquare + 1, false);
  for (int i = 1; i <= n; ++i) {
    isSquare[i * i] = true;
  }

  int count = 0;
  for (int a = 1; a <= n; ++a) {
    int a2 = a * a;
    for (int b = 1; b <= n; ++b) {
      int sum = a2 + b * b;
      if (sum <= maxSquare && isSquare[sum]) {
        ++count;
      }
    }
  }
  return count;
}

CountSquareSumTriplesSolution::CountSquareSumTriplesSolution() {
  setMetaInfo({.id = 1925,
               .title = "Count Square Sum Triples",
               .url = "https://leetcode.com/problems/count-square-sum-triples/"});
  registerStrategy({.name = "BruteForce",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(n^2)",
                    .tags = {"Math", "Enumeration"}},
                   countTriplesImpl);
}

int CountSquareSumTriplesSolution::countTriples(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_1925
