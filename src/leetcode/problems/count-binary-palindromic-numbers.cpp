#include "leetcode/problems/count-binary-palindromic-numbers.h"

namespace leetcode::problem_3677 {

// Count binary palindromes of exactly the given bit length.
// len=1: "0" and "1" → 2.
// len>=2: first bit fixed to 1, remaining (len-1) bits form a palindrome,
//         so free bits = floor((len-1)/2).
static long long countExactLength(int len) {
  if (len == 1) return 2;
  int freeBits = (len - 1) / 2;
  return 1LL << freeBits;
}

// Build the binary palindrome of given length from its first half (prefix).
// prefix has m = ceil(len/2) bits.
static long long buildPalindrome(long long prefix, int len) {
  long long result = prefix;
  int m = (len + 1) / 2;
  long long p = prefix;
  if (len % 2 == 1) {
    p >>= 1;  // remove middle bit before mirroring
  }
  int remaining = len - m;
  for (int i = 0; i < remaining; ++i) {
    result = (result << 1) | (p & 1);
    p >>= 1;
  }
  return result;
}

// Bit length of n (n > 0).
static int bitLength(long long n) {
  int len = 0;
  while (n > 0) {
    n >>= 1;
    ++len;
  }
  return len;
}

static int countBinaryPalindromesImpl(long long n) {
  if (n == 0) return 1;

  int len = bitLength(n);

  // 1. Count all palindromes with length < len.
  long long total = 0;
  for (int L = 1; L < len; ++L) {
    total += countExactLength(L);
  }

  // 2. Count palindromes of length == len that are <= n.
  int m = (len + 1) / 2;  // ceil(len/2)
  long long half = n >> (len - m);  // first m bits of n
  long long minPrefix = (len == 1) ? 0 : (1LL << (m - 1));

  // All prefixes strictly less than half produce palindromes < n.
  if (half > minPrefix) {
    total += (half - minPrefix);
  }

  // Check the palindrome formed by prefix == half.
  long long pal = buildPalindrome(half, len);
  if (pal <= n) {
    ++total;
  }

  return static_cast<int>(total);
}

CountBinaryPalindromicNumbersSolution::CountBinaryPalindromicNumbersSolution() {
  setMetaInfo({.id = 3677,
               .title = "Count Binary Palindromic Numbers",
               .url = "https://leetcode.com/problems/count-binary-palindromic-numbers/"});
  registerStrategy(
      {.name = "Combinatorial by length",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(log n)",
       .tags = {"Math", "Bit Manipulation"}},
      countBinaryPalindromesImpl);
  setDefaultStrategy();
}

int CountBinaryPalindromicNumbersSolution::countBinaryPalindromes(long long n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_3677
