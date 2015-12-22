#include "gtest.h"
#include "postfix.h"
#include "postfix.cpp"


TEST(postfix, throw_then_incorret_bracket_find)
{
	string Row;
	Row="a+b(";
	ASSERT_ANY_THROW(convert(Row));
}

TEST(postfix, throw_then_open_bracket_not_find)
{
	string Row;
	Row="a+b)";
	ASSERT_ANY_THROW(convert(Row));
}
TEST(postfix, throw_if_string_empty)
{
	string Row;
	Row=" ";
	ASSERT_ANY_THROW(convert(Row));
}
TEST(postfix, work_fine)
{
	string Row;
	Row="a+b";
	EXPECT_EQ("ab+",convert(Row));
}

TEST(postfix, throw_if_incorrectly_string)
{
	string Row;
	Row="@#";
	ASSERT_ANY_THROW(convert(Row));
}
TEST(postfix, throw_then_close_bracket_not_find)
{
	string Row;
	Row="(a+b";
	ASSERT_ANY_THROW(convert(Row));
}