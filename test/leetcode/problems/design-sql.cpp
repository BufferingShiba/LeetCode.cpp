#include <gtest/gtest.h>

#include "leetcode/problems/design-sql.h"

using namespace leetcode::problem_2408;

class DesignSqlTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

// Example 1 from the problem description
TEST_P(DesignSqlTest, Example1) {
  std::vector<std::string> names = {"one", "two", "three"};
  std::vector<int> columns = {2, 3, 1};
  SQL sql(names, columns);

  EXPECT_TRUE(sql.ins("two", {"first", "second", "third"}));
  EXPECT_EQ(sql.sel("two", 1, 3), "third");
  EXPECT_TRUE(sql.ins("two", {"fourth", "fifth", "sixth"}));

  auto exp1 = sql.exp("two");
  ASSERT_EQ(exp1.size(), 2);
  EXPECT_EQ(exp1[0], "1,first,second,third");
  EXPECT_EQ(exp1[1], "2,fourth,fifth,sixth");

  sql.rmv("two", 1);
  EXPECT_EQ(sql.sel("two", 2, 2), "fifth");

  auto exp2 = sql.exp("two");
  ASSERT_EQ(exp2.size(), 1);
  EXPECT_EQ(exp2[0], "2,fourth,fifth,sixth");
}

// Example 2 from the problem description
TEST_P(DesignSqlTest, Example2) {
  std::vector<std::string> names = {"one", "two", "three"};
  std::vector<int> columns = {2, 3, 1};
  SQL sql(names, columns);

  EXPECT_TRUE(sql.ins("two", {"first", "second", "third"}));
  EXPECT_EQ(sql.sel("two", 1, 3), "third");
  sql.rmv("two", 1);
  EXPECT_EQ(sql.sel("two", 1, 2), "<null>");
  EXPECT_FALSE(sql.ins("two", {"fourth", "fifth"}));
  EXPECT_TRUE(sql.ins("two", {"fourth", "fifth", "sixth"}));
}

// Invalid table name on all operations
TEST_P(DesignSqlTest, InvalidTableName) {
  std::vector<std::string> names = {"t"};
  std::vector<int> columns = {1};
  SQL sql(names, columns);

  EXPECT_FALSE(sql.ins("nonexistent", {"a"}));
  sql.rmv("nonexistent", 1);  // no-op, no crash
  EXPECT_EQ(sql.sel("nonexistent", 1, 1), "<null>");
  EXPECT_TRUE(sql.exp("nonexistent").empty());
}

// Column count mismatch
TEST_P(DesignSqlTest, ColumnCountMismatch) {
  std::vector<std::string> names = {"t"};
  std::vector<int> columns = {3};
  SQL sql(names, columns);

  EXPECT_FALSE(sql.ins("t", {"a"}));           // too few
  EXPECT_FALSE(sql.ins("t", {"a", "b", "c", "d"}));  // too many
  EXPECT_TRUE(sql.ins("t", {"a", "b", "c"}));  // correct
}

// ID continues incrementing after removal
TEST_P(DesignSqlTest, IdContinuesAfterRemoval) {
  std::vector<std::string> names = {"t"};
  std::vector<int> columns = {1};
  SQL sql(names, columns);

  EXPECT_TRUE(sql.ins("t", {"a"}));   // id = 1
  EXPECT_TRUE(sql.ins("t", {"b"}));   // id = 2
  sql.rmv("t", 1);
  EXPECT_TRUE(sql.ins("t", {"c"}));   // id = 3, not 1

  auto exp_result = sql.exp("t");
  ASSERT_EQ(exp_result.size(), 2);
  EXPECT_EQ(exp_result[0], "2,b");
  EXPECT_EQ(exp_result[1], "3,c");
}

// Invalid rowId and columnId for sel
TEST_P(DesignSqlTest, InvalidCellSelection) {
  std::vector<std::string> names = {"t"};
  std::vector<int> columns = {2};
  SQL sql(names, columns);

  sql.ins("t", {"x", "y"});  // id = 1

  EXPECT_EQ(sql.sel("t", 999, 1), "<null>");   // bad rowId
  EXPECT_EQ(sql.sel("t", 1, 0), "<null>");     // columnId < 1
  EXPECT_EQ(sql.sel("t", 1, 3), "<null>");     // columnId > columns
  EXPECT_EQ(sql.sel("t", 1, 1), "x");          // valid
  EXPECT_EQ(sql.sel("t", 1, 2), "y");          // valid
}

// Empty table export
TEST_P(DesignSqlTest, EmptyTableExport) {
  std::vector<std::string> names = {"t"};
  std::vector<int> columns = {1};
  SQL sql(names, columns);

  EXPECT_TRUE(sql.exp("t").empty());
}

// Multiple tables isolation
TEST_P(DesignSqlTest, MultipleTablesIsolation) {
  std::vector<std::string> names = {"a", "b"};
  std::vector<int> columns = {2, 1};
  SQL sql(names, columns);

  EXPECT_TRUE(sql.ins("a", {"x1", "x2"}));  // id=1 in a
  EXPECT_TRUE(sql.ins("b", {"y1"}));         // id=1 in b
  EXPECT_TRUE(sql.ins("a", {"x3", "x4"}));  // id=2 in a

  auto exp_a = sql.exp("a");
  ASSERT_EQ(exp_a.size(), 2);
  EXPECT_EQ(exp_a[0], "1,x1,x2");
  EXPECT_EQ(exp_a[1], "2,x3,x4");

  auto exp_b = sql.exp("b");
  ASSERT_EQ(exp_b.size(), 1);
  EXPECT_EQ(exp_b[0], "1,y1");
}

INSTANTIATE_TEST_SUITE_P(
    DesignSqlTests,
    DesignSqlTest,
    ::testing::Values(0));
