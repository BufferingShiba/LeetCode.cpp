#include "leetcode/problems/ransom-note.h"

#include <array>

namespace leetcode::problem_383 {

namespace {

bool canConstructImpl(std::string ransomNote, std::string magazine) {
    std::array<int, 26> count{};
    for (char c : magazine) {
        ++count[c - 'a'];
    }
    for (char c : ransomNote) {
        if (--count[c - 'a'] < 0) {
            return false;
        }
    }
    return true;
}

}  // namespace

RansomNoteSolution::RansomNoteSolution() {
    setMetaInfo({.id = 383,
                 .title = "Ransom Note",
                 .url = "https://leetcode.com/problems/ransom-note/"});
    registerStrategy({.name = "Frequency Counting",
                      .expected = "Accepted",
                      .time_complexity = "O(n + m)",
                      .space_complexity = "O(1)",
                      .tags = {"Hash Table", "String", "Counting"}},
                     canConstructImpl);
}

bool RansomNoteSolution::canConstruct(std::string ransomNote, std::string magazine) {
    return getSolution()(std::move(ransomNote), std::move(magazine));
}

}  // namespace leetcode::problem_383
