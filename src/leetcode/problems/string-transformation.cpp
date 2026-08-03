#include "leetcode/problems/string-transformation.h"

#include <vector>

namespace leetcode::problem_2851 {

namespace {

constexpr int MOD = 1000000007;

using Mat = std::vector<std::vector<long long>>;

Mat matMul(const Mat& a, const Mat& b) {
  int m = a.size(), p = b[0].size(), n = b.size();
  Mat c(m, std::vector<long long>(p, 0));
  for (int i = 0; i < m; ++i) {
    for (int k = 0; k < n; ++k) {
      if (a[i][k] == 0) continue;
      for (int j = 0; j < p; ++j) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return c;
}

Mat matPow(Mat base, long long e) {
  int n = base.size();
  Mat res(n, std::vector<long long>(n, 0));
  for (int i = 0; i < n; ++i) res[i][i] = 1;
  while (e > 0) {
    if (e & 1) res = matMul(res, base);
    base = matMul(base, base);
    e >>= 1;
  }
  return res;
}

std::vector<int> zFunction(const std::string& str) {
  int n = (int)str.size();
  std::vector<int> z(n, 0);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i < r) z[i] = std::min(r - i, z[i - l]);
    while (i + z[i] < n && str[z[i]] == str[i + z[i]]) ++z[i];
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int countCyclicMatches(const std::string& s, const std::string& t) {
  int n = (int)s.size();
  std::string combined = t;
  combined.push_back('#');
  combined += s;
  combined += s;
  std::vector<int> z = zFunction(combined);
  int offset = n + 1;
  int c = 0;
  for (int r = 0; r < n; ++r) {
    if (z[offset + r] >= n) ++c;
  }
  return c;
}

int numberOfWaysImpl(const std::string& s, const std::string& t, long long k) {
  int n = (int)s.size();
  long long c = countCyclicMatches(s, t);
  if (c == 0) return 0;

  // Row vector [good, bad]; after one step:
  //   good' = good*(c-1) + bad*c
  //   bad'  = good*(n-c) + bad*(n-1-c)
  // Transition matrix rows correspond to "from" states.
  Mat trans = {{(long long)(c - 1), (long long)(n - c)},
               {c, (long long)(n - 1 - c)}};

  long long good0 = (s == t) ? 1 : 0;
  long long bad0 = 1 - good0;

  Mat res = matPow(trans, k);
  // good_k = good0 * trans^k[0][0] + bad0 * trans^k[1][0]
  long long ans = (res[0][0] * good0 + res[1][0] * bad0) % MOD;
  ans = (ans % MOD + MOD) % MOD;
  return (int)ans;
}

}  // namespace

StringTransformationSolution::StringTransformationSolution() {
  setMetaInfo({.id = 2851,
               .title = "String Transformation",
               .url = "https://leetcode.com/problems/string-transformation/"});
  registerStrategy(
      {"matrix-power", "Accepted", "O(n + log k)", "O(n)",
       {"Math", "String", "Dynamic Programming", "String Matching"}},
      numberOfWaysImpl);
}

int StringTransformationSolution::numberOfWays(std::string s, std::string t,
                                               long long k) {
  return getSolution()(std::move(s), std::move(t), k);
}

}  // namespace leetcode::problem_2851
