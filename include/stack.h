#pragma once
#include "list.h"
 
template <class ValType>
class Stack 
{
private:
 	List<ValType> *nList;
public:
 	Stack();
 	Stack(const Stack<ValType> &s);
 	int isEmpty() const;
 	int isFull() const;
 	void push(ValType key);
 	ValType pop();
	ValType printS();
}; 

template <class ValType>
Stack<ValType>::Stack()
{
	nList = new List<ValType>();
}
template <class ValType>
Stack<ValType>::Stack(const Stack<ValType> &s)
{
	this->nList=new List<ValType>(*(s.nList)); 
}
template <class ValType>
int Stack<ValType>::isEmpty() const
{
	return nList->getFirst()==0;
}
template <class ValType>
int Stack<ValType>::isFull() const
{
	NODE<ValType> *tmp;
	try
	{
		tmp=new NODE<ValType>;
	}
	catch(...)
	{
		return 1;
	}
	delete tmp;
	return 0;
}
template <class ValType>
void Stack<ValType>::push(ValType key)
{
	if(isFull()) 
		throw "FULL_STACK";
	nList->insertF(key);
}
template <class ValType>
ValType Stack<ValType>::pop()
{
	if(isEmpty()) 
		throw "EMPTY_STACK";
	ValType res=nList->getFirst()->key;
	nList->erase(res);
	return res;
}
template <class ValType>
ValType Stack<ValType>::printS()
{
	if(isEmpty()) 
		throw "EMPTY_STACK";
	return nList->getFirst()->key;
}