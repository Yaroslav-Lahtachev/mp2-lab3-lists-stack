#pragma once
#include <iostream>


template <class ValType>
class NODE
{
public:
	ValType key;
	NODE<ValType> *pNext;
};
template <class ValType>
class List{
private:
	NODE<ValType>* pFirst;
public:
	List();
	// List(const List &list); 
	NODE<ValType>* find(ValType key);
	NODE<ValType>* findP(ValType key);
	void erase(ValType key);
	void insertF(ValType key);
	void insertL(ValType key);
	void insertB(ValType key, NODE<ValType> *elem);
	void insertA(ValType key, NODE<ValType> *elem);
	void print();
	NODE<ValType>* getFirst();
};




template <class ValType>
List::List()
{
	pFirst = 0;
}
//List::List(const List &list){}

template <class ValType>
NODE<ValType>* List::find(ValType key)
{
	if (pFirst==0)
		return 0;
	NODE<ValType> *tmp=pFirst;
	while((tmp->pNext!=0)&&(tmp->key!=key))
		tmp=tmp->pNext;
	if (tmp->key!=key) 
		return 0;
	return (tmp);
}
template <class ValType>
NODE<ValType>* List::findP(ValType key)
{	
	if (pFirst==0)
		return 0;
	NODE<ValType> *tmp=pFirst;
	if (tmp->key==key)
		return tmp;
	while((tmp->pNext->pNext!=0)&&(tmp->pNext->key!=key))
		tmp=tmp->pNext;
	if (tmp->pNext->key!=key) 
		return 0;
	return (tmp);
}
template <class ValType>
void List<ValType>::insertF(ValType key)
{
	NODE<ValType> *tmp=new NODE<ValType>;
	tmp->key=key;
	tmp->pNext=pFirst;
	pFirst=tmp;
}
template <class ValType>
void List<ValType>::insertL(ValType key)
{
	NODE<ValType> *tmp=pFirst;
	while(tmp->pNext!=0)
		tmp=tmp->pNext;
	tmp->pNext=new NODE<ValType>;
	tmp=tmp->pNext;
	tmp->key=key;
	tmp->pNext=0;
}
template <class ValType>
void List<ValType>::insertB(ValType key, NODE<ValType> *elem)
{	
	NODE<ValType> *point=findP(key);
	if ((point==0)&&(pFirst->key!=key)) 
		return;
	elem->pNext=point->pNext->pNext;
	if (point==0)	
	{
		pFirst=elem;
		return;
	}
	point->pNext=elem;
}
template <class ValType>
void List<ValType>::insertA(ValType key, NODE<ValType> *elem)
{
	NODE<ValType> *point=find(key);
	if (point==0)
		return;
	elem->pNext=point->pNext;
	point->pNext=elem;
}
template <class ValType>
void List<ValType>::erase(ValType key)
{
	NODE<ValType> *tmp =findP(key);
	if(tmp==pFirst)
	{
		pFirst->pNext=pFirst->pNext->pNext;
		delete tmp->pNext;
	}
	else if(tmp->pNext->pNext==0)
		tmp->pNext=0;
	else 
		{
			NODE<ValType> *tmp1=tmp->pNext;
			tmp->pNext=tmp->pNext->pNext;
			delete tmp1;
		}
}
template <class ValType>
void List<ValType>::print()
{
	NODE<ValType> *tmp=pFirst;
	if (pFirst==0) 
		return;
	while(tmp!=0)	
	{
		cout<<tmp->key<<endl;
		tmp=tmp->pNext;
	}
}
template <class ValType>
NODE<ValType>* List::getFirst()
{
	return pFirst;
}