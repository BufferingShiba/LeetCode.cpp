#include "leetcode/problems/count-almost-equal-pairs-ii.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode::problem_3267 {

static int countPairsImpl(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    // Precompute all reachable sets
    std::vector<std::unordered_set<int>> reachable(n);
    for (int i = 0; i < n; i++) {
        std::string s = std::to_string(nums[i]);
        int len = static_cast<int>(s.size());
        std::unordered_set<int> s_set;
        s_set.insert(nums[i]);  // 0 swaps

        // 1 swap
        for (int a = 0; a < len; a++) {
            for (int b = a + 1; b < len; b++) {
                std::string t = s;
                std::swap(t[a], t[b]);
                s_set.insert(std::stoi(t));
            }
        }

        // 2 swaps
        for (int a = 0; a < len; a++) {
            for (int b = a + 1; b < len; b++) {
                std::string t1 = s;
                std::swap(t1[a], t1[b]);
                for (int c = 0; c < len; c++) {
                    for (int d = c + 1; d < len; d++) {
                        std::string t2 = t1;
                        std::swap(t2[c], t2[d]);
                        s_set.insert(std::stoi(t2));
                    }
                }
            }
        }

        reachable[i] = std::move(s_set);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (reachable[i].count(nums[j]) || reachable[j].count(nums[i])) {
                ans++;
            }
        }
    }
    return ans;
}

CountAlmostEqualPairsIiSolution::CountAlmostEqualPairsIiSolution() {
    setMetaInfo({.id = 3267, .title = "Count Almost Equal Pairs II", .url = "https://leetcode.com/problems/count-almost-equal-pairs-ii/"});
    registerStrategy({
        .name = "brute_force_reachable_sets",
        .expected = "Accepted",
        .time_complexity = "O(n * d^4 + n^2)",
        .space_complexity = "O(n * d^4)",
        .tags = {"Array", "Hash Table", "Enumeration", "Brute Force"}
    }, countPairsImpl);
}

int CountAlmostEqualPairsIiSolution::countPairs(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace leetcode::problem_3267
