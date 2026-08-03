#include "leetcode/problems/count-of-matches-in-tournament.h"

namespace leetcode {
namespace problem_1688 {

// Every match eliminates exactly one team. To crown a single champion among
// n teams, exactly n - 1 eliminations are required, hence n - 1 matches.
static int numberOfMatchesFormula(int n) { return n - 1; }

CountOfMatchesInTournamentSolution::CountOfMatchesInTournamentSolution() {
  setMetaInfo({.id = 1688,
               .title = "Count of Matches in Tournament",
               .url = "https://leetcode.com/problems/count-of-matches-in-tournament/"});
  registerStrategy(
      {.name = "MathFormula",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"},
       .notes = "Each match eliminates one team; champion needs n-1 eliminations."},
      numberOfMatchesFormula);
}

}  // namespace problem_1688
}  // namespace leetcode
