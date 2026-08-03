#include "leetcode/problems/gcd-sort-of-an-array.h"

#include <algorithm>
#include <cstddef>
#include <vector>

namespace leetcode {
namespace problem_1998 {

namespace {

constexpr int kMaxVal = 100000;

std::vector<int> buildSpf() {
    std::vector<int> spf(kMaxVal + 1, 0);
    for (int i = 2; i <= kMaxVal; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j <= kMaxVal; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    return spf;
}

class UnionFind {
public:
    explicit UnionFind(int n) : parent_(n), rank_(n, 0) {
        for (int i = 0; i < n; ++i) parent_[i] = i;
    }
    int find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank_[a] < rank_[b]) std::swap(a, b);
        parent_[b] = a;
        if (rank_[a] == rank_[b]) ++rank_[a];
    }

private:
    std::vector<int> parent_;
    std::vector<int> rank_;
};

bool gcdSortImpl(std::vector<int>& nums) {
    static const std::vector<int> spf = buildSpf();
    UnionFind uf(kMaxVal + 1);
    for (int x : nums) {
        int v = x;
        while (v > 1) {
            int p = spf[v];
            uf.unite(x, p);
            while (v % p == 0) v /= p;
        }
    }
    std::vector<int> sorted = nums;
    std::sort(sorted.begin(), sorted.end());
    for (std::size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == sorted[i]) continue;
        if (uf.find(nums[i]) != uf.find(sorted[i])) return false;
    }
    return true;
}

}  // namespace

GcdSortOfAnArraySolution::GcdSortOfAnArraySolution() {
    setMetaInfo({.id = 1998,
                 .title = "GCD Sort of an Array",
                 .url = "https://leetcode.com/problems/gcd-sort-of-an-array/"});
    registerStrategy({.name = "UnionFindPrimeFactor",
                      .expected = "Accepted",
                      .time_complexity = "O(N * log(maxVal))",
                      .space_complexity = "O(maxVal)",
                      .tags = {"Array", "Math", "Union-Find", "Sorting", "Number Theory"}},
                     gcdSortImpl);
}

bool GcdSortOfAnArraySolution::gcdSort(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_1998
}  // namespace leetcode
