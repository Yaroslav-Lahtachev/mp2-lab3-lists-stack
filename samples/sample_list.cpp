#include "list.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	List<int> list;
	cout<<"�������� ������, ������� �����"<<endl;
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
	cout<<"��������� ������ "<<endl;
	list.print();

	cout<<"�������� ����� ������"<<endl;
	List<int> list1(list);
	list1.print();

	cout<<"���������� �������� � ������ ������, ������� ����"<<endl;
	cin>>n;
	list1.insertF(n);
	list1.print();

	cout<<"���������� �������� � ����� ������, ������� ����"<<endl;
	cin>>n;
	list1.insertL(n);
	list1.print();

	cout<<"���������� ��������� �������� ����� ��� ������������"<<endl;
	NODE<int> *elem = new NODE<int>;
	cout<<"������� ���� ������ ��������"<<endl;
	cin>>n;
	elem->key = n;
	cout<<"������� ���� �������� ����� ������� ����� ������� �������"<<endl;
	cin>>n;
	list1.insertB(n, elem);
	list1.print();

	cout<<"���������� ��������� �������� ����� ��� �������������"<<endl;
	NODE<int> *elem1 = new NODE<int>;
	cout<<"������� ���� ������ ��������"<<endl;
	cin>>n;
	elem1->key = n;
	cout<<"������� ���� �������� ����� �������� ����� ������� �������"<<endl;
	cin>>n;
	list1.insertA(n, elem1);
	list1.print();
	
	cout<<"�������� ������������� ��������"<<endl;
	cout<<"������� ���� ���������� ��������"<<endl;
	cin>>n;
	list1.erase(n);
	list1.print();

	cout<<"��������� �������� ������� ��������"<<endl;
	cout<<list1.getFirst()->key<<endl;

	cout<<"��������� ���������� ����� � ��������� ������"<<endl;
	list1.print();
	list.print();
	system("pause");
	return 0;
}