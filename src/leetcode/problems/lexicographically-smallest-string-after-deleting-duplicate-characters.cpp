#include "leetcode/problems/lexicographically-smallest-string-after-deleting-duplicate-characters.h"

#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace leetcode::problem_3816 {

namespace {

std::string lexSmallestAfterDeletionImpl(std::string s) {
    const int n = static_cast<int>(s.size());
    std::array<std::vector<int>, 26> positions;
    int required = 0;
    for (int i = 0; i < n; ++i) {
        const int index = s[i] - 'a';
        positions[index].push_back(i);
        required |= 1 << index;
    }

    std::string result;
    result.reserve(n);
    int mask = 0;
    int current_position = -1;

    // Greedily choose the smallest next character that still leaves an
    // occurrence of every not-yet-seen character to its right.  Choosing the
    // earliest feasible occurrence of the same character is always optimal:
    // it leaves a superset of the suffixes available to a later occurrence.
    while (mask != required) {
        for (int character = 0; character < 26; ++character) {
            if (positions[character].empty()) continue;

            const auto next = std::upper_bound(
                positions[character].begin(), positions[character].end(),
                current_position);
            if (next == positions[character].end()) continue;
            const int candidate_position = *next;
            const int next_mask = mask | (1 << character);

            int latest_allowed = n;
            for (int missing = 0; missing < 26; ++missing) {
                if ((required & (1 << missing)) != 0 &&
                    (next_mask & (1 << missing)) == 0) {
                    latest_allowed = std::min(
                        latest_allowed, positions[missing].back());
                }
            }

            // A missing character must have an occurrence strictly after the
            // selected position; otherwise selecting this candidate would
            // make a complete subsequence impossible.
            if (candidate_position >= latest_allowed) continue;

            result.push_back(static_cast<char>('a' + character));
            current_position = candidate_position;
            mask = next_mask;
            break;
        }
    }

    return result;
}

}  // namespace

LexSmallestAfterDeletionSolution::LexSmallestAfterDeletionSolution() {
    setMetaInfo({.id = 3816,
                 .title = "Lexicographically Smallest String After Deleting Duplicate Characters",
                 .url = "https://leetcode.com/problems/lexicographically-smallest-string-after-deleting-duplicate-characters"});
    registerStrategy({.name = "monotonic-stack",
                      .expected = "O(n)",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(n)",
                      .tags = {"Stack", "Greedy", "Monotonic Stack"}},
                     lexSmallestAfterDeletionImpl);
}

std::string LexSmallestAfterDeletionSolution::lexSmallestAfterDeletion(std::string s) {
    return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3816
