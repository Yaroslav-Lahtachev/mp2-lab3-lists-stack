#include "postfix.h"
#include "postfix.cpp"



void main()
{
	setlocale(LC_ALL, "Russian");
	string Row,postfix;
	float res;
	try
	{
		cout<<"������� ��������� ���������"<<endl;
		cin>>Row;
		postfix=convert(Row);
		cout<<"������� �������� ����������"<<endl;
		res = result(postfix);
		cout<<endl;
	}
	catch(...)
	{
		cout<<"����������� ������� ������"<<endl;
		return;
	}
	cout<<"����������� ���������:  "<<postfix<<endl;
	cout<<"���������:  "<<res<<endl;
	system("pause");
}

