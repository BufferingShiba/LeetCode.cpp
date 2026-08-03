#include "leetcode/problems/mirror-frequency-distance.h"

namespace leetcode::problem_3889 {

namespace {

int mirror(int c) {
    if (c >= 'a' && c <= 'z') {
        return 'a' + ('z' - c);
    }
    return '0' + ('9' - c);
}

int mirrorFrequencyCount(std::string s) {
    int freq[128] = {0};
    for (char c : s) {
        ++freq[static_cast<unsigned char>(c)];
    }

    bool visited[128] = {false};
    int total = 0;
    for (char c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (visited[uc]) {
            continue;
        }
        int mc = mirror(c);
        int diff = freq[uc] - freq[mc];
        if (diff < 0) {
            diff = -diff;
        }
        total += diff;
        visited[uc] = true;
        visited[mc] = true;
    }
    return total;
}

}  // namespace

MirrorFrequencyDistanceSolution::MirrorFrequencyDistanceSolution() {
    setMetaInfo({.id = 3889,
                 .title = "Mirror Frequency Distance",
                 .url = "https://leetcode.com/problems/mirror-frequency-distance/"});
    registerStrategy(
        {.name = "frequency-count",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Hash Table", "String", "Counting"},
         .notes = "Count frequencies then sum absolute diffs over distinct mirror pairs"},
        mirrorFrequencyCount);
}

int MirrorFrequencyDistanceSolution::mirrorFrequency(std::string s) {
    return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3889
