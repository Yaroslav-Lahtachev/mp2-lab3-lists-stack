#pragma once
#include "list.h"
 
template <class ValType>
class Stack 
{
private:
 	List<ValType> *nList;
public:
 	Stack();
 	Stack(const Stack &s);
 	int isEmpty() const;
 	int isFull() const;
 	void push(ValType key);
 	ValType pop();
	ValType printS();
}; 

template <class ValType>
Stack::Stack()
{
	nList = new List();
}
//Stack::Stack(const Stack &s){}
template <class ValType>
int Stack::isEmpty() const
{
	return nList->getFirst()==0;
}
template <class ValType>
int Stack::isFull() const
{
	NODE *tmp;
	try{
		tmp=new NODE;}
	catch(...){
		return 1;}
	delete tmp;
	return 0;
}
template <class ValType>
void Stack::push(ValType key)
{
	if(isFull()) throw "Full";
	nList->insertF(key);
}
template <class ValType>
ValType Stack::pop()
{
	if(isEmpty()) throw "Empty";
	ValType res=nList->getFirst()->key;
	nList->erase(res);
	return res;
}
template <class ValType>
ValType Stack::printS()
{
	if(isEmpty()) throw "Empty";
	return nList->getFirst()->key;
}