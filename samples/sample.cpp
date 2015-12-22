#include "postfix.h"
#include "postfix.cpp"



void main()
{
	setlocale(LC_ALL, "Russian");
	string Row,postfix;
	float res;
	try
	{
		cout<<"введите инфиксное выражение"<<endl;
		cin>>Row;
		postfix=convert(Row);
		cout<<"введите значения переменных"<<endl;
		res = result(postfix);
		cout<<endl;
	}
	catch(...)
	{
		cout<<"некоректные входные данные"<<endl;
		return;
	}
	cout<<"постфиксное выражение:  "<<postfix<<endl;
	cout<<"результат:  "<<res<<endl;
	system("pause");
}

