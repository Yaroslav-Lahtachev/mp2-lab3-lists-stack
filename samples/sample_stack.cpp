#include "stack.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	Stack<int> stack;
	cout<<"создание стека, введите ключи"<<endl;
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
	
	cout<<"первый элемент стека"<<endl;
	cout <<stack.top()<<endl;

	cout<<"копирование стека"<<endl;
	Stack<int> stack1(stack);
		
	cout<<"добавление нового елемента в копию"<<endl;
	cin>>n;
	stack1.push(n);
	
	cout<<"сравнение измененной копии стека с исходным"<<endl;
	cout<<"измененная копия: ";
	while(stack1.isEmpty()==0)
		cout<<stack1.pop()<<" ";
	cout<<endl;
	cout<<"исходный стек:    ";
	while(stack.isEmpty()==0)
		cout<<stack.pop()<<" ";

	system("pause");
	return 0;
}