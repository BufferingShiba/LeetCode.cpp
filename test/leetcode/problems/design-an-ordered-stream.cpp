#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "leetcode/problems/design-an-ordered-stream.h"

namespace leetcode {
namespace problem_1656 {

using namespace leetcode::problem_1656;

struct Operation {
  enum class Type { Insert };
  Type type;
  int idKey;
  std::string value;
  std::vector<std::string> expected;
};

struct OrderedStreamTestCase {
  int n;
  std::vector<Operation> ops;
};

class DesignAnOrderedStreamTest : public ::testing::TestWithParam<int> {};

TEST_P(DesignAnOrderedStreamTest, OfficialExample) {
  OrderedStreamTestCase tc{5, {}};
  tc.ops = {
      {Operation::Type::Insert, 3, "ccccc", {}},
      {Operation::Type::Insert, 1, "aaaaa", {"aaaaa"}},
      {Operation::Type::Insert, 2, "bbbbb", {"bbbbb", "ccccc"}},
      {Operation::Type::Insert, 5, "eeeee", {}},
      {Operation::Type::Insert, 4, "ddddd", {"ddddd", "eeeee"}},
  };

  OrderedStream os(tc.n);
  for (const auto& op : tc.ops) {
    auto result = os.insert(op.idKey, op.value);
    EXPECT_EQ(op.expected, result);
  }
}

TEST_P(DesignAnOrderedStreamTest, SequentialInsertionReturnsAll) {
  OrderedStream os(3);
  EXPECT_EQ(std::vector<std::string>{}, os.insert(1, "aaaaa") == std::vector<std::string>{} ? std::vector<std::string>{"aaaaa"} : std::vector<std::string>{});
  // sequential insert in order returns each single value chunk
  OrderedStream os2(3);
  EXPECT_EQ(std::vector<std::string>({"a"}), os2.insert(1, "a"));
  EXPECT_EQ(std::vector<std::string>({"b"}), os2.insert(2, "b"));
  EXPECT_EQ(std::vector<std::string>({"c"}), os2.insert(3, "c"));
}

INSTANTIATE_TEST_SUITE_P(DesignAnOrderedStreamTestSuite, DesignAnOrderedStreamTest,
                         ::testing::Values(0));

}  // namespace problem_1656
}  // namespace leetcode
