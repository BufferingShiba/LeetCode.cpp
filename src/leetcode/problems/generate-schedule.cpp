#include "leetcode/problems/generate-schedule.h"

#include <algorithm>
#include <array>
#include <numeric>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3680 {
namespace {

using Match = std::array<int, 2>;

bool disjoint(const Match& lhs, const Match& rhs) {
  return lhs[0] != rhs[0] && lhs[0] != rhs[1] &&
         lhs[1] != rhs[0] && lhs[1] != rhs[1];
}

// The circle method decomposes every unordered match into disjoint rounds.
// For odd n, one dummy team supplies the bye in each round.
std::vector<std::vector<Match>> makeRounds(int n) {
  const int circle_size = n % 2 == 0 ? n : n + 1;
  const int dummy = n % 2 == 0 ? -1 : n;

  std::vector<int> circle(circle_size);
  std::iota(circle.begin(), circle.end(), 0);

  std::vector<std::vector<Match>> rounds;
  rounds.reserve(circle_size - 1);
  for (int round = 0; round < circle_size - 1; ++round) {
    std::vector<Match> matches;
    matches.reserve(circle_size / 2);
    for (int i = 0; i < circle_size / 2; ++i) {
      const int home = circle[i];
      const int away = circle[circle_size - 1 - i];
      if (home != dummy && away != dummy) {
        matches.push_back({home, away});
      }
    }
    rounds.push_back(std::move(matches));

    // Keep circle[0] fixed and rotate all other teams by one position.
    std::rotate(circle.begin() + 1, circle.end() - 1, circle.end());
  }
  return rounds;
}

std::vector<std::vector<int>> generateScheduleImpl(int n) {
  // With four or fewer teams, every possible next match shares a team with
  // the previous one before all unordered pairs can be exhausted.
  if (n <= 4) {
    return {};
  }

  // The five-team instance has only two matches per round in the circle
  // decomposition; its fixed round order has no compatible boundary.  This
  // compact base schedule is the unique small case needed before the general
  // construction below.
  if (n == 5) {
    return {{0, 1}, {2, 3}, {0, 4}, {3, 2}, {1, 0},
            {2, 4}, {1, 3}, {4, 0}, {3, 1}, {4, 2},
            {0, 3}, {1, 2}, {3, 0}, {1, 4}, {0, 2},
            {4, 1}, {2, 0}, {3, 4}, {2, 1}, {4, 3}};
  }

  const auto unordered_rounds = makeRounds(n);
  const int round_count = static_cast<int>(unordered_rounds.size());

  // The second copy has the opposite home/away direction.  A schedule is
  // obtained by choosing an order inside each matching and joining adjacent
  // rounds only when their boundary matches are disjoint.
  std::vector<std::vector<Match>> rounds;
  rounds.reserve(round_count * 2);
  for (int direction = 0; direction < 2; ++direction) {
    for (const auto& unordered_round : unordered_rounds) {
      std::vector<Match> current;
      current.reserve(unordered_round.size());
      for (const Match& match : unordered_round) {
        current.push_back(direction == 0 ? match
                                        : Match{match[1], match[0]});
      }
      rounds.push_back(std::move(current));
    }
  }

  const int matches_per_round = static_cast<int>(rounds.front().size());
  if (matches_per_round < 2) {
    return {};
  }

  // possible[last] says that the previous round can end with its match at
  // index last.  For each reachable ending match, remember the first match
  // chosen for the current round and the preceding ending match.
  std::vector<char> possible(matches_per_round, false);
  std::vector<std::vector<int>> first(
      round_count * 2, std::vector<int>(matches_per_round, -1));
  std::vector<std::vector<int>> previous(
      round_count * 2, std::vector<int>(matches_per_round, -1));

  for (int round = 0; round < round_count * 2; ++round) {
    std::vector<char> next(matches_per_round, false);
    for (int previous_last = 0; previous_last < matches_per_round;
         ++previous_last) {
      if (round != 0 && !possible[previous_last]) {
        continue;
      }
      for (int current_first = 0; current_first < matches_per_round;
           ++current_first) {
        if (round != 0 &&
            !disjoint(rounds[round - 1][previous_last],
                      rounds[round][current_first])) {
          continue;
        }
        for (int current_last = 0; current_last < matches_per_round;
             ++current_last) {
          if (current_first == current_last || next[current_last]) {
            continue;
          }
          next[current_last] = true;
          first[round][current_last] = current_first;
          previous[round][current_last] =
              round == 0 ? -1 : previous_last;
        }
      }
    }
    possible = std::move(next);
  }

  int last = -1;
  for (int i = 0; i < matches_per_round; ++i) {
    if (possible[i]) {
      last = i;
      break;
    }
  }
  if (last == -1) {
    return {};
  }

  std::vector<std::vector<Match>> ordered(round_count * 2);
  for (int round = round_count * 2 - 1; round >= 0; --round) {
    const int current_first = first[round][last];
    const int current_last = last;
    ordered[round].push_back(rounds[round][current_first]);
    for (int i = 0; i < matches_per_round; ++i) {
      if (i != current_first && i != current_last) {
        ordered[round].push_back(rounds[round][i]);
      }
    }
    ordered[round].push_back(rounds[round][current_last]);
    last = previous[round][current_last];
  }

  std::vector<std::vector<int>> answer;
  answer.reserve(n * (n - 1));
  for (const auto& round : ordered) {
    for (const Match& match : round) {
      answer.push_back({match[0], match[1]});
    }
  }
  return answer;
}

}  // namespace

GenerateScheduleSolution::GenerateScheduleSolution() {
  setMetaInfo({.id = 3680,
               .title = "Generate Schedule",
               .url = "https://leetcode.com/problems/generate-schedule/"});
  registerStrategy(
      {.name = "circle_method_dp",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"Constructive", "Dynamic Programming"},
       .notes = "Build round-robin matchings and choose compatible round boundaries."},
      generateScheduleImpl);
}

std::vector<std::vector<int>> GenerateScheduleSolution::generateSchedule(int n) {
  return getSolution()(n);
}

}  // namespace problem_3680
}  // namespace leetcode
