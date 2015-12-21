#include "gtest.h"
#include "list.h"

TEST(List, can_create_list)
{
	List<int> *list;
	ASSERT_NO_THROW(list = new List<int>());
}
TEST(List, can_create_copied_list)
{
	List<int> list;
	ASSERT_NO_THROW(List<int> list1(list));
}
TEST(List, copied_list_is_equal_to_sourse_one)
{
	List<int> list;
	list.insertL(0);
	List<int> list1(list);
	EXPECT_EQ(list.getFirst()->key,list1.getFirst()->key);
}
TEST(List, copied_list_has_its_own_memory)
{
	List<int> list;
	list.insertL(1);
	List<int> list1(list);
	list1.insertL(2);
	list1.erase(1);
	EXPECT_NE(list1.getFirst()->key, list.getFirst()->key);
}
TEST(List, can_search_element) 
{
	List<int> list;
	list.insertL(1);
	ASSERT_TRUE(list.find(1)!=0);
}
TEST(List, can_not_search_in_empty_list)
{
	List<int> list;
	ASSERT_ANY_THROW(list.find(1));
}

TEST(List, if_elem_not_found_null) 
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	list.insertL(3);
	ASSERT_TRUE(list.find(4)==0);
}
TEST(List, can_find_prev_elem) 
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	list.insertL(3);
	NODE<int> *elem = new NODE<int>;
	ASSERT_TRUE(list.findP(3,elem)!=0);
}
TEST(List, throw_findP_in_empty_list) 
{
	List<int> list;
	NODE<int> *elem = new NODE<int>;
	ASSERT_ANY_THROW(list.findP(4,elem));
}
TEST(List, throw_if_prev_elem_not_found) 
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	list.insertL(3);
	NODE<int> *elem = new NODE<int>;
	ASSERT_ANY_THROW(list.findP(4,elem));
}


TEST(List, erase_from_empty_list) 
{
	List<int> list;
	ASSERT_ANY_THROW(list.erase(1));
}
TEST(List, can_erase_element) 
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	ASSERT_NO_THROW(list.erase(2));
}
TEST(List, can_not_erase_elem_if_it_not_found) 
{
	List<int> list;
	list.insertL(1);
	ASSERT_ANY_THROW(list.erase(2));
}
TEST(List, can_erase_first_element) 
{
	List<int> list;
	list.insertL(1);
    list.insertL(2);
    list.erase(1);
	EXPECT_EQ(2,list.getFirst()->key);
}
TEST(List, can_insert_first_elem) 
{
	List<int> list;
	ASSERT_NO_THROW(list.insertF(1));
}
TEST(List, can_insert_last_elem) 
{
	List<int> list;
	list.insertF(1);
	ASSERT_NO_THROW(list.insertL(2));
}
TEST(List, can_insert_last_elem_when_list_empty) 
{
	List<int> list;
	ASSERT_NO_THROW(list.insertL(2));
}
TEST(List, can_insert_elem_before) 
{
	List<int> list;
	NODE<int> *elem = new NODE<int>;
	list.insertL(1);
	list.insertL(2);
	elem->key=3;
	ASSERT_NO_THROW(list.insertB(2, elem));
}
TEST(List, can_insert_elem_after) 
{
	List<int> list;
	NODE<int> *elem=new NODE<int>;
	list.insertL(1);
	list.insertL(2);
	elem->key=3;
	ASSERT_NO_THROW(list.insertA(1, elem));
}
TEST(List, can_insert_after_last_elem) 
{
	List<int> list;
	NODE<int> *elem = new NODE<int>;
	list.insertL(1);
	list.insertL(2);
	elem->key=3;
	ASSERT_NO_THROW(list.insertA(2, elem));
}
TEST(List, can_insert_before_when_it_first) 
{
	List<int> list;
	NODE<int> *elem = new NODE<int>;
	list.insertL(1);
	list.insertL(2);
	elem->key=3;
	ASSERT_NO_THROW(list.insertB(1, elem));
}
TEST(List, can_not_insert_after_when_key_not_found) 
{
	List<int> list;
	list.insertL(5);
	list.insertL(7);
	list.insertL(9);
	NODE<int> *elem = new NODE<int>;
	elem->key = 1;
	ASSERT_ANY_THROW(list.insertA(8, elem));
}
TEST(List, can_not_insert_before_when_key_not_found) 
{
	List<int> list;
	NODE<int> *elem = new NODE<int>;
	elem->key = 1;
	ASSERT_ANY_THROW(list.insertB(5, elem));
}

TEST(List, can_not_insert_before_when_list_empty) 
{
	List<int> list;
	NODE<int> *elem = new NODE<int>;
	elem->key=3;
	ASSERT_ANY_THROW(list.insertA(4, elem));
}
TEST(List, can_not_insert_after_when_list_empty) 
{
	List<int> list;
	NODE<int> *elem = new NODE<int>;
	elem->key=3;
	ASSERT_ANY_THROW(list.insertA(4, elem));
}
TEST(List, can_print_list) 
{
	List<int> list;
	list.insertL(1);
	ASSERT_NO_THROW(list.print());
}

TEST(List, can_print_empty_list) 
{
	List<int> list;
	ASSERT_NO_THROW(list.print());
}
TEST(List, can_get_first) 
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	ASSERT_NO_THROW(list.getFirst());
}

TEST(List, can_get_first_key)
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	EXPECT_EQ(1, list.getFirst()->key);
}
TEST(List, elem_real_added_first)
{
	List<int> list;
	list.insertL(1);
	list.insertF(2);
	EXPECT_EQ(2, list.getFirst()->key);
}
TEST(List, elem_real_added_last)
{
	List<int> list;
	list.insertL(2);
	EXPECT_EQ(2, list.getFirst()->key);
}
TEST(List, elem_real_added_before)
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	NODE<int> *elem = new NODE<int>;
	elem->key=3;
	list.insertB(2,elem);
	EXPECT_EQ(2, list.find(3)->pNext->key);
}
TEST(List, elem_real_added_after)
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	NODE<int> *elem = new NODE<int>;
	elem->key=3;
	list.insertA(1,elem);
	EXPECT_EQ(2, list.find(3)->pNext->key);
}
TEST(List, elem_real_deleted)
{
	List<int> list;
	list.insertL(1);
	list.insertL(2);
	list.erase(2);
	ASSERT_TRUE(list.find(2)==0);
}