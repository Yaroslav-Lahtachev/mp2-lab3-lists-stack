#include "list.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	List<int> list;
	cout<<"создание списка, введите ключи"<<endl;
	cin>>n;
	list.insertL(n);
	cin>>n;
	list.insertL(n);
	cin>>n;
	list.insertL(n);
	cin>>n;
	list.insertL(n);
	cin>>n;
	list.insertL(n);
	cout<<"созданный список "<<endl;
	list.print();

	cout<<"создание копии списка"<<endl;
	List<int> list1(list);
	list1.print();

	cout<<"добавление элемента в начало списка, введите ключ"<<endl;
	cin>>n;
	list1.insertF(n);
	list1.print();

	cout<<"добавление элемента в конец списка, введите ключ"<<endl;
	cin>>n;
	list1.insertL(n);
	list1.print();

	cout<<"добавление заданного элемента перед уже существующим"<<endl;
	NODE<int> *elem = new NODE<int>;
	cout<<"введите ключ нового элемента"<<endl;
	cin>>n;
	elem->key = n;
	cout<<"введите ключ элемента перед которым будет сделана вставка"<<endl;
	cin>>n;
	list1.insertB(n, elem);
	list1.print();

	cout<<"добавление заданного элемента после уже существующего"<<endl;
	NODE<int> *elem1 = new NODE<int>;
	cout<<"введите ключ нового элемента"<<endl;
	cin>>n;
	elem1->key = n;
	cout<<"введите ключ элемента после которого будет сделана вставка"<<endl;
	cin>>n;
	list1.insertA(n, elem1);
	list1.print();
	
	cout<<"удаление существующего элемента"<<endl;
	cout<<"введите ключ удаляемого элемента"<<endl;
	cin>>n;
	list1.erase(n);
	list1.print();

	cout<<"выведение значения первого элемента"<<endl;
	cout<<list1.getFirst()->key<<endl;

	cout<<"сравнение измененной копии и исходного списка"<<endl;
	list1.print();
	list.print();
	system("pause");
	return 0;
}