#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/encode-and-decode-tinyurl.h"

namespace leetcode {
namespace problem_535 {

class EncodeAndDecodeTinyurlTest : public testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(EncodeAndDecodeTinyurlTest, Example1) {
  Solution obj;
  std::string url = "https://leetcode.com/problems/design-tinyurl";
  std::string tiny = obj.encode(url);
  std::string ans = obj.decode(tiny);
  EXPECT_EQ(ans, url);
}

TEST_P(EncodeAndDecodeTinyurlTest, SelfAuthoredEncodeDecodeMultipleUrls) {
  Solution obj;
  std::vector<std::string> urls = {
      "https://www.example.com/page1",
      "https://www.example.com/page2",
      "https://www.example.com/page3",
  };

  for (const auto& url : urls) {
    std::string tiny = obj.encode(url);
    std::string decoded = obj.decode(tiny);
    EXPECT_EQ(decoded, url);
    // Tiny URL should start with the prefix
    EXPECT_TRUE(tiny.find("http://tinyurl.com/") == 0);
  }
}

TEST_P(EncodeAndDecodeTinyurlTest, SelfAuthoredSameUrlReturnsSameTiny) {
  Solution obj;
  std::string url = "https://leetcode.com/problems/design-tinyurl";
  std::string tiny1 = obj.encode(url);
  std::string tiny2 = obj.encode(url);
  EXPECT_EQ(tiny1, tiny2);
}

TEST_P(EncodeAndDecodeTinyurlTest, SelfAuthoredDifferentUrlsReturnDifferentTiny) {
  Solution obj;
  std::string url1 = "https://www.example.com/a";
  std::string url2 = "https://www.example.com/b";
  std::string tiny1 = obj.encode(url1);
  std::string tiny2 = obj.encode(url2);
  EXPECT_NE(tiny1, tiny2);
}

TEST_P(EncodeAndDecodeTinyurlTest, SelfAuthoredDecodeOnlyShortCode) {
  Solution obj;
  std::string url = "https://leetcode.com/problems/design-tinyurl";
  std::string tiny = obj.encode(url);
  // Extract the short code part only
  size_t pos = tiny.rfind('/');
  std::string shortCode =
      (pos != std::string::npos) ? tiny.substr(pos + 1) : tiny;
  std::string decoded = obj.decode(shortCode);
  EXPECT_EQ(decoded, url);
}

INSTANTIATE_TEST_SUITE_P(All, EncodeAndDecodeTinyurlTest,
                         testing::Values(0));

}  // namespace problem_535
}  // namespace leetcode
