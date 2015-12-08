#include "list.h"
using namespace std;


List::List()
{
	pFirst = 0;
}
//List::List(const List &list){}
NODE* List::find(val key)
{
	if (pFirst==0)
		return 0;
	NODE *tmp=pFirst;
	while((tmp->pNext!=0)&&(tmp->key!=key))
		tmp=tmp->pNext;
	if (tmp->key!=key) 
		return 0;
	return (tmp);
}
NODE* List::findP(val key)
{	
	if (pFirst==0)
		return 0;
	NODE *tmp=pFirst;
	if (tmp->key==key)
		return tmp;
	while((tmp->pNext->pNext!=0)&&(tmp->pNext->key!=key))
		tmp=tmp->pNext;
	if (tmp->pNext->key!=key) 
		return 0;
	return (tmp);
}
void List::insertF(val key)
{
	NODE *tmp=new NODE;
	tmp->key=key;
	tmp->pNext=pFirst;
	pFirst=tmp;
}
void List::insertL(val key)
{
	NODE *tmp=pFirst;
	while(tmp->pNext!=0)
		tmp=tmp->pNext;
	tmp->pNext=new NODE;
	tmp=tmp->pNext;
	tmp->key=key;
	tmp->pNext=0;
}
void List::insertB(val key, NODE *elem)
{	
	NODE *point=findP(key);
	if ((point==0)&&(pFirst->key!=key)) 
		return;
	elem->pNext=elem;
	if (point==0)	
	{
		pFirst=elem;
		return;
	}
	point->pNext=elem;
}
void List::insertA(val key, NODE *elem)
{
	NODE *point=find(key);
	if (point==0)
		return;
	elem->pNext=point->pNext;
	point->pNext=elem;
}
void List::erase(val key)
{
	NODE *tmp =findP(key);
	if(tmp==pFirst)
	{
		pFirst=pFirst->pNext;
		delete tmp;
	}
	else if(tmp->pNext->pNext==0)
		tmp->pNext=0;
	else 
		{
			NODE *tmp1=tmp->pNext;
			tmp->pNext=tmp->pNext->pNext;
			delete tmp1;
		}
}
void List::print()
{
	NODE *tmp=pFirst;
	if (pFirst==0) 
		return;
	while(tmp!=0)	
	{
		cout<<tmp->key<<endl;
		tmp=tmp->pNext;
	}
}
NODE* List::getFirst()
{
	return pFirst;
}