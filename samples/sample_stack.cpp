#include "stack.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	Stack<int> stack;
	cout<<"�������� �����, ������� �����"<<endl;
	cin>>n;
	stack.push(n);
	cin>>n;
	stack.push(n);
	cin>>n;
	stack.push(n);
	cin>>n;
	stack.push(n);
	cin>>n;
	stack.push(n);
	
	cout<<"������ ������� �����"<<endl;
	cout <<stack.top()<<endl;

	cout<<"����������� �����"<<endl;
	Stack<int> stack1(stack);
		
	cout<<"���������� ������ �������� � �����"<<endl;
	cin>>n;
	stack1.push(n);
	
	cout<<"��������� ���������� ����� ����� � ��������"<<endl;
	cout<<"���������� �����: ";
	while(stack1.isEmpty()==0)
		cout<<stack1.pop()<<" ";
	cout<<endl;
	cout<<"�������� ����:    ";
	while(stack.isEmpty()==0)
		cout<<stack.pop()<<" ";

	system("pause");
	return 0;
}