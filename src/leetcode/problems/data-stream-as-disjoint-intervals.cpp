#include "leetcode/problems/data-stream-as-disjoint-intervals.h"

namespace leetcode {
namespace problem_352 {

SummaryRanges::SummaryRanges() {}

void SummaryRanges::addNum(int value) {
    // Find first interval with start > value
    auto it = intervals_.upper_bound(value);

    // Check if value is already covered by the previous interval
    if (it != intervals_.begin()) {
        auto prev = std::prev(it);
        if (value <= prev->second) {
            return; // already inside an interval
        }
    }

    int newStart = value;
    int newEnd = value;

    // Check if value is exactly before the next interval (value + 1 == next->first)
    if (it != intervals_.end() && it->first == value + 1) {
        newEnd = it->second;
        it = intervals_.erase(it); // erase returns the following iterator
    }

    // Check if value is exactly after the previous interval (prev->second + 1 == value)
    if (it != intervals_.begin()) {
        auto prev = std::prev(it);
        if (prev->second == value - 1) {
            newStart = prev->first;
            intervals_.erase(prev);
        }
    }

    intervals_[newStart] = newEnd;
}

std::vector<std::vector<int>> SummaryRanges::getIntervals() {
    std::vector<std::vector<int>> result;
    for (const auto& interval : intervals_) {
        result.push_back({interval.first, interval.second});
    }
    return result;
}

} // namespace problem_352
} // namespace leetcode
