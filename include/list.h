#pragma once
#include <iostream>

typedef unsigned char val;
struct NODE
{
	val key;
	NODE *pNext;
};

class List{
private:
	NODE* pFirst;
public:
	List();
	// List(const List &list); 
	NODE* find(val key);
	NODE* findP(val key);
	void erase(val key);
	void insertF(val key);
	void insertL(val key);
	void insertB(val key, NODE *elem);
	void insertA(val key, NODE *elem);
	void print();
	NODE* getFirst();
};