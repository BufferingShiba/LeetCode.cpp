#include "leetcode/problems/count-no-zero-pairs-that-sum-to-n.h"

#include <tuple>
#include <vector>
#include <map>
#include <functional>

namespace leetcode {
namespace problem_3704 {
namespace {

using ll = long long;

// Count number of ordered pairs (a, b) with:
//   a, b no-zero positive integers, a + b = n.
//
// Digit DP over positions from low (units) to high, using addition carry.
// A no-zero positive integer has its units digit nonzero, and upper digits
// (from a lowest position up to its top nonzero digit) are all nonzero; the
// remaining higher-most digits are all zero (leading zeros aren't digits).
// We model each number's digit pattern from low to high as:
//   a run of nonzero digits ("active"), then optional switch to all-zero
//   for every higher position ("leading"). This exactly captures no-zero.
ll countNoZeroPairsImpl(ll n) {
    std::vector<int> d;
    ll t = n;
    while (t > 0) {
        d.push_back(static_cast<int>(t % 10));
        t /= 10;
    }
    const int k = static_cast<int>(d.size());

    std::map<std::tuple<int, int, int, int>, ll> memo;
    // f(pos, carry, a_phase, b_phase)
    //   phase 0 = still in nonzero run; phase 1 = entered leading (must be 0).
    std::function<ll(int, int, int, int)> f =
        [&](int pos, int carry, int aph, int bph) -> ll {
        if (pos == k) {
            return carry == 0 ? 1 : 0;
        }
        auto key = std::make_tuple(pos, carry, aph, bph);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        std::vector<int> aChoices;
        if (pos == 0) {
            // units digit must be nonzero for a no-zero positive number
            for (int x = 1; x <= 9; ++x) aChoices.push_back(x);
        } else if (aph == 0) {
            for (int x = 1; x <= 9; ++x) aChoices.push_back(x);
            aChoices.push_back(0);
        } else {
            aChoices.push_back(0);
        }

        std::vector<int> bChoices;
        if (pos == 0) {
            for (int x = 1; x <= 9; ++x) bChoices.push_back(x);
        } else if (bph == 0) {
            for (int x = 1; x <= 9; ++x) bChoices.push_back(x);
            bChoices.push_back(0);
        } else {
            bChoices.push_back(0);
        }

        ll total = 0;
        for (int ai : aChoices) {
            for (int bi : bChoices) {
                int sum = ai + bi + carry;
                if (sum % 10 != d[pos]) continue;
                int co = sum / 10;
                int naph = (pos > 0 && ai == 0) ? 1 : aph;
                int nbph = (pos > 0 && bi == 0) ? 1 : bph;
                total += f(pos + 1, co, naph, nbph);
            }
        }
        memo[key] = total;
        return total;
    };

    return f(0, 0, 0, 0);
}

}  // namespace

CountNoZeroPairsSolution::CountNoZeroPairsSolution() {
    setMetaInfo({
        .id = 3704,
        .title = "Count No-Zero Pairs That Sum to N",
        .url = "https://leetcode.com/problems/count-no-zero-pairs-that-sum-to-n/",
    });
    registerStrategy({
        .name = "digit-dp",
        .expected = "",
        .time_complexity = "O(k * 2^3 * 100)",
        .space_complexity = "O(k * 2^3)",
        .tags = {"Math", "Dynamic Programming"},
    }, countNoZeroPairsImpl);
}

long long CountNoZeroPairsSolution::countNoZeroPairs(long long n) {
    return getSolution()(n);
}

}  // namespace problem_3704
}  // namespace leetcode
