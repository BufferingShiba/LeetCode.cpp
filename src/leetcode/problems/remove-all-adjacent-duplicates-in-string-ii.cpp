#include "leetcode/problems/remove-all-adjacent-duplicates-in-string-ii.h"

#include <utility>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1209 {

namespace {

// 单栈：栈中每个元素为 [字符, 该字符连续出现的次数]。
// 遍历时累计连续计数，达到 k 即弹出该组。
std::string removeDuplicatesImpl(std::string s, int k) {
    std::vector<std::pair<char, int>> stack;
    stack.reserve(s.size());
    for (char c : s) {
        if (!stack.empty() && stack.back().first == c) {
            ++stack.back().second;
            if (stack.back().second == k) {
                stack.pop_back();
            }
        } else {
            stack.push_back({c, 1});
        }
    }
    std::string result;
    result.reserve(s.size());
    for (const auto& entry : stack) {
        result.append(static_cast<size_t>(entry.second), entry.first);
    }
    return result;
}

}  // namespace

RemoveAllAdjacentDuplicatesInStringIiSolution::RemoveAllAdjacentDuplicatesInStringIiSolution() {
    setMetaInfo({.id = 1209,
                 .title = "Remove All Adjacent Duplicates in String II",
                 .url =
                     "https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/"});
    registerStrategy({.name = "CountingStack",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(n)",
                      .tags = {"String", "Stack"}},
                     +[](std::string s, int k) -> std::string {
                         return removeDuplicatesImpl(std::move(s), k);
                     });
}

std::string RemoveAllAdjacentDuplicatesInStringIiSolution::removeDuplicates(
    std::string s, int k) {
    return getSolution()(std::move(s), k);
}

}  // namespace problem_1209
}  // namespace leetcode
