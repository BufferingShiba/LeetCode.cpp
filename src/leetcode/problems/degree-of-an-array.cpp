#include "leetcode/problems/degree-of-an-array.h"

#include <unordered_map>

namespace leetcode {
namespace problem_697 {

namespace {

int findShortestSubArrayImpl(std::vector<int>& nums) {
    std::unordered_map<int, int> count;
    std::unordered_map<int, int> first;
    std::unordered_map<int, int> last;
    int degree = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int v = nums[i];
        if (count.find(v) == count.end()) {
            first[v] = i;
        }
        count[v] = count[v] + 1;
        last[v] = i;
        degree = std::max(degree, count[v]);
    }

    int result = nums.size();
    for (const auto& kv : count) {
        if (kv.second == degree) {
            int len = last[kv.first] - first[kv.first] + 1;
            result = std::min(result, len);
        }
    }
    return result;
}

}  // namespace

DegreeOfAnArraySolution::DegreeOfAnArraySolution() {
    setMetaInfo({.id = 697,
                 .title = "Degree of an Array",
                 .url = "https://leetcode.com/problems/degree-of-an-array/"});
    registerStrategy({.name = "HashTable",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(n)",
                      .tags = {"Array", "Hash Table"}},
                     &findShortestSubArrayImpl);
}

int DegreeOfAnArraySolution::findShortestSubArray(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_697
}  // namespace leetcode
