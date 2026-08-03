#include "leetcode/problems/double-modular-exponentiation.h"

namespace leetcode::problem_2961 {
namespace {

long long powMod(long long base, long long exp, long long mod) {
    long long result = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

std::vector<int> getGoodIndicesImpl(std::vector<std::vector<int>>& variables,
                                    int target) {
    std::vector<int> result;
    for (int i = 0; i < static_cast<int>(variables.size()); ++i) {
        const auto& v = variables[i];
        int a = v[0], b = v[1], c = v[2], m = v[3];
        long long inner = powMod(a, b, 10);
        if (powMod(inner, c, m) == target) {
            result.push_back(i);
        }
    }
    return result;
}

}  // namespace

DoubleModularExponentiationSolution::DoubleModularExponentiationSolution() {
    setMetaInfo({.id = 2961,
                 .title = "Double Modular Exponentiation",
                 .url = "https://leetcode.com/problems/double-modular-exponentiation/"});
    registerStrategy({.name = "pow-mod",
                      .expected = "Accepted",
                      .time_complexity = "O(n log B)",
                      .space_complexity = "O(1)",
                      .tags = {"Array", "Math", "Simulation"}},
                     getGoodIndicesImpl);
}

std::vector<int> DoubleModularExponentiationSolution::getGoodIndices(
    std::vector<std::vector<int>>& variables, int target) {
    return getSolution()(variables, target);
}

}  // namespace leetcode::problem_2961
