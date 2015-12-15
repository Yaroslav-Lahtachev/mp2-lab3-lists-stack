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
	List(const List &list); 
	NODE<ValType>* find(ValType key);
	NODE<ValType>* findP(ValType key, NODE<ValType> *&elem);
	void erase(ValType key);
	void insertF(ValType key);
	void insertL(ValType key);
	void insertB(ValType key, NODE<ValType> *elem);
	void insertA(ValType key, NODE<ValType> *elem);
	void print();
	NODE<ValType>* getFirst();
};




template <class ValType>
List<ValType>::List()
{
	pFirst = 0;
}
template <class ValType>
List<ValType>::List(const List<ValType> &list)
{
	pFirst = 0;
	NODE<ValType> *tmp=list.pFirst;
	while(tmp!=0)
	{
		insertL(tmp->key);
		tmp=tmp->pNext;
	}
}

template <class ValType>
NODE<ValType> *List<ValType>::find(ValType key)
{
	if (pFirst==0)
		throw "EMPTY_LIST";
	NODE<ValType> *tmp=pFirst;
	while((tmp->pNext!=0)&&(tmp->key!=key))
		tmp=tmp->pNext;
	if (tmp->key!=key) 
		throw "ELEM_NOT_FOUND";
	return (tmp);
}
template <class ValType>
NODE<ValType>* List<ValType>::findP(ValType key, NODE<ValType> *&elem)
{	
	if (pFirst==0)
		throw "EMPTY_LIST";
	NODE<ValType> *tmp=pFirst;
	elem=pFirst;
	while((elem->pNext!=0)&&(elem->key!=key))
	{
		elem=elem->pNext;
		tmp=elem;
	}
	if ((elem->key!=key)||(elem==0))
	{
		elem=0;
		return 0;
	}
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
	if(tmp==0)
	{
		insertF(key);
		return;
	}
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
	if (pFirst==0) throw "EMPTY_LIST";
	NODE<ValType> *p;
	NODE<ValType> *tmp=findP(key,p);
	if ((tmp==0)&&(pFirst->key!=key)) 
		throw "KEY_NOT_FOUND";
	elem->pNext=p;
	if (tmp==0)	
	{
		pFirst=elem;
		return;
	}
	tmp->pNext=elem;
}
template <class ValType>
void List<ValType>::insertA(ValType key, NODE<ValType> *elem)
{
	if (pFirst==0) throw "EMPTY_LIST";
	NODE<ValType> *point=find(key);
	if (point==0)
		throw "KEY_NOT_FOUND";
	elem->pNext=point->pNext;
	point->pNext=elem;
}
template <class ValType>
void List<ValType>::erase(ValType key)
{
	if (pFirst==0) throw "EMPTY_LIST";
	NODE<ValType> *elem;
	NODE<ValType> *tmp =findP(key,elem);
	if ((tmp==0)&&(pFirst->key!=key)) 
		throw "ELEM_NOT_FOUND";
	if(tmp==0)
	{
		pFirst=pFirst->pNext;
		delete elem;
		return;
	}
	
		tmp->pNext=elem->pNext;
		delete elem;
		return;
}
template <class ValType>
void List<ValType>::print()
{
	NODE<ValType> *tmp=pFirst;
	if (pFirst==0) 
		return;
	while(tmp!=0)	
	{
		std::cout<<tmp->key<<std::endl;
		tmp=tmp->pNext;
	}
}
template <class ValType>
NODE<ValType>* List<ValType>::getFirst()
{
	return pFirst;
}