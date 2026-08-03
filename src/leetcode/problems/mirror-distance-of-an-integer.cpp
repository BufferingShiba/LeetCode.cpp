#include "leetcode/problems/mirror-distance-of-an-integer.h"

namespace leetcode {
namespace problem_3783 {

namespace {

int mirrorDistanceImpl(int n) {
    int original = n;
    long long reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return static_cast<int>(std::abs(static_cast<long long>(original) - reversed));
}

}  // namespace

MirrorDistanceOfAnIntegerSolution::MirrorDistanceOfAnIntegerSolution() {
    setMetaInfo({.id = 3783,
                 .title = "Mirror Distance of an Integer",
                 .url = "https://leetcode.com/problems/mirror-distance-of-an-integer/"});
    registerStrategy({.name = "MathReverseDigits",
                      .expected = "Accepted",
                      .time_complexity = "O(num_digits)",
                      .space_complexity = "O(1)",
                      .tags = {"Math"}},
                     mirrorDistanceImpl);
}

int MirrorDistanceOfAnIntegerSolution::mirrorDistance(int n) {
    return getSolution()(n);
}

}  // namespace problem_3783
}  // namespace leetcode
