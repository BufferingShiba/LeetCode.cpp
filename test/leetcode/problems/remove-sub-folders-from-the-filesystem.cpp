#include <gtest/gtest.h>

#include "leetcode/problems/remove-sub-folders-from-the-filesystem.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1233 {
namespace {

using testing::TestWithParam;
using testing::ValuesIn;

using InputType = std::vector<std::string>;
using ExpectedType = std::vector<std::string>;

ExpectedType normalize(InputType in) {
  std::sort(in.begin(), in.end());
  return in;
}

}  // namespace

class RemoveSubFoldersFromTheFilesystemTest
    : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveSubFoldersFromTheFilesystemSolution solution;
};

TEST_P(RemoveSubFoldersFromTheFilesystemTest, Example1) {
  auto folder =
      std::vector<std::string>{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
  auto result = solution.removeSubfolders(folder);
  EXPECT_EQ((ExpectedType{"/a", "/c/d", "/c/f"}), normalize(std::move(result)));
}

TEST_P(RemoveSubFoldersFromTheFilesystemTest, Example2) {
  auto folder = std::vector<std::string>{"/a", "/a/b/c", "/a/b/d"};
  auto result = solution.removeSubfolders(folder);
  EXPECT_EQ((ExpectedType{"/a"}), normalize(std::move(result)));
}

TEST_P(RemoveSubFoldersFromTheFilesystemTest, Example3) {
  auto folder = std::vector<std::string>{"/a/b/c", "/a/b/ca", "/a/b/d"};
  auto result = solution.removeSubfolders(folder);
  EXPECT_EQ((ExpectedType{"/a/b/c", "/a/b/ca", "/a/b/d"}),
            normalize(std::move(result)));
}

TEST_P(RemoveSubFoldersFromTheFilesystemTest, NestedMultipleLevels) {
  auto folder = std::vector<std::string>{"/a", "/a/b", "/a/b/c", "/x/y"};
  auto result = solution.removeSubfolders(folder);
  EXPECT_EQ((ExpectedType{"/a", "/x/y"}), normalize(std::move(result)));
}

TEST_P(RemoveSubFoldersFromTheFilesystemTest, NoSubfolders) {
  auto folder = std::vector<std::string>{"/a/b/c", "/x/y/z"};
  auto result = solution.removeSubfolders(folder);
  EXPECT_EQ((ExpectedType{"/a/b/c", "/x/y/z"}),
            normalize(std::move(result)));
}

namespace {

RemoveSubFoldersFromTheFilesystemSolution kDefaultSolution;

}  // namespace

INSTANTIATE_TEST_SUITE_P(
    RemoveSubFoldersFromTheFilesystemSuite,
    RemoveSubFoldersFromTheFilesystemTest,
    ValuesIn(kDefaultSolution.getStrategyNames()));

}  // namespace problem_1233
}  // namespace leetcode
