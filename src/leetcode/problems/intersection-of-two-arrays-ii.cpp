#include "leetcode/problems/intersection-of-two-arrays-ii.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode::problem_350 {

namespace {

std::vector<int> intersectImpl(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
    // Count occurrences in the smaller array to save memory.
    if (nums1.size() > nums2.size()) {
        std::swap(nums1, nums2);
    }

    std::unordered_map<int, int> count;
    for (int num : nums1) {
        ++count[num];
    }

    std::vector<int> result;
    result.reserve(nums1.size());
    for (int num : nums2) {
        auto it = count.find(num);
        if (it != count.end() && it->second > 0) {
            result.push_back(num);
            --it->second;
        }
    }
    return result;
}

}  // namespace

IntersectionOfTwoArraysIiSolution::IntersectionOfTwoArraysIiSolution() {
    setMetaInfo({.id = 350,
                 .title = "Intersection of Two Arrays II",
                 .url = "https://leetcode.com/problems/intersection-of-two-arrays-ii/"});
    registerStrategy(
        {"hash-map", "Accepted", "O(n + m)", "O(min(n, m))",
         {"Hash Table"}},
        intersectImpl);
}

std::vector<int> IntersectionOfTwoArraysIiSolution::intersect(
    std::vector<int>& nums1, std::vector<int>& nums2) {
    return getSolution()(nums1, nums2);
}

}  // namespace leetcode::problem_350
