#pragma once
#include "list.h"
 
class Stack 
{
private:
 	List *nList;
public:
 	Stack();
 	Stack(const Stack &s);
 	int isEmpty() const;
 	int isFull() const;
 	void push(val key);
 	val pop();
	val printS();
}; 
