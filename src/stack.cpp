#include "stack.h"
Stack::Stack()
{
	nList = new List();
}
//Stack::Stack(const Stack &s){}
int Stack::isEmpty() const
{
	return nList->getFirst()==0;
}
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
void Stack::push(val key)
{
	if(isFull()) throw "Full";
	nList->insertF(key);
}
val Stack::pop()
{
	if(isEmpty()) throw "Empty";
	val res=nList->getFirst()->key;
	nList->erase(res);
	return res;
}
val Stack::printS()
{
	if(isEmpty()) throw "Empty";
	return nList->getFirst()->key;
}