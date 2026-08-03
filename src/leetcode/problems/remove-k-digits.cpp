#include "leetcode/problems/remove-k-digits.h"

#include <string>

namespace leetcode {
namespace problem_402 {

static std::string removeKdigitsImpl(std::string num, int k) {
    std::string stack;
    stack.reserve(num.size());
    for (char c : num) {
        while (!stack.empty() && k > 0 && stack.back() > c) {
            stack.pop_back();
            --k;
        }
        stack.push_back(c);
    }
    // 如果还有剩余删除配额，从末尾删除
    while (k > 0 && !stack.empty()) {
        stack.pop_back();
        --k;
    }
    // 去除前导零
    int start = 0;
    while (start < static_cast<int>(stack.size()) && stack[start] == '0') {
        ++start;
    }
    if (start == static_cast<int>(stack.size())) {
        return "0";
    }
    return stack.substr(start);
}

RemoveKDigitsSolution::RemoveKDigitsSolution() {
    setMetaInfo({.id = 402,
                 .title = "Remove K Digits",
                 .url = "https://leetcode.com/problems/remove-k-digits/"});
    registerStrategy(
        {.name = "MonotonicStack",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(n)",
         .tags = {"String", "Stack", "Greedy", "Monotonic Stack"}},
        removeKdigitsImpl);
}

std::string RemoveKDigitsSolution::removeKdigits(std::string num, int k) {
    return getSolution()(num, k);
}

}  // namespace problem_402
}  // namespace leetcode
