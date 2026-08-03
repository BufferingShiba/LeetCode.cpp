#include "leetcode/problems/faulty-keyboard.h"
#include <deque>
#include <string>
#include <algorithm>

namespace leetcode {
namespace problem_2810 {

static std::string finalStringImpl(std::string s) {
    std::deque<char> dq;
    bool reversed = false;
    for (char c : s) {
        if (c == 'i') {
            reversed = !reversed;
        } else {
            if (reversed) {
                dq.push_front(c);
            } else {
                dq.push_back(c);
            }
        }
    }
    std::string result(dq.begin(), dq.end());
    if (reversed) {
        std::reverse(result.begin(), result.end());
    }
    return result;
}

FaultyKeyboardSolution::FaultyKeyboardSolution() {
    setMetaInfo({.id = 2810, .title = "Faulty Keyboard", .url = "https://leetcode.com/problems/faulty-keyboard/"});
    registerStrategy({
        .name = "Deque",
        .expected = "Accepted",
        .time_complexity = "O(n)",
        .space_complexity = "O(n)",
        .tags = {"String", "Simulation", "Deque"}
    }, finalStringImpl);
}

std::string FaultyKeyboardSolution::finalString(std::string s) {
    return getSolution()(s);
}

}  // namespace problem_2810
}  // namespace leetcode
