#include "postfix.h"

string convert(string Row)
{
	Stack<char> sign;
	Stack<char> row;
	map<char,int> s;
	s['*'] = 3;
	s['/'] = 3;
	s['+'] = 2;
	s['-'] = 2;
	s['('] = 1;
	s['='] = 0;
	char elem;
	for (int i = 0; i < Row.length(); i++){
		elem = Row[i];
		if((elem>=0x61)&&(elem<=0x7A))	
		{						
			row.push(elem);
			continue;
		}
		if(s.count(elem))
		{
			if((sign.isEmpty()==0)&&(s[elem]<=s[sign.top()])&&(elem!='('))
				while((sign.isEmpty()==0)&&(s[elem]<= s[sign.top()]))
					row.push(sign.pop());	
				sign.push(elem);
			continue;
		}
		if (elem==')')
		{														
			while((sign.isEmpty()==0)&&(sign.top()!='('))									
				row.push(sign.pop());							
			if (sign.isEmpty())										
				throw "INCORRECT_EXPRESSION";				
			sign.pop();
			continue;
		}
		throw "WRONG ROW";
	}
	while(sign.isEmpty()==0)
	{
		if(sign.top()=='(')
			throw "INCORRECT_EXPRESSION";
		row.push(sign.pop());
	}
	string res;
	string tmp;
	if(row.isEmpty())
		throw "EMPTY";
	while(row.isEmpty()==0)
	{
		tmp = row.pop();
		res.insert(0, tmp);
	}
	return res;
}
float result(string Row)
{
	Stack<float> row;
	char elem;
	float first,second;
	map<char, float> nums;
	for(int i=0;i<Row.length();i++)
	{
		elem=Row[i];
		if(Row[Row.length()-1]=='=')
			nums[Row[0]]=0;
		if((elem>=0x61)&&(elem<=0x7A))
		{
			if (nums.count(elem)==0)
			{
				cout<<elem<<"=";
				cin>>nums[elem];
			}
			row.push(nums[elem]);
			continue;
		}
		second=row.pop();
		first=row.pop();
		switch (elem)
		{
		case '+':{row.push(first+second); break;}
		case '-':{row.push(first-second); break;}
		case '*':{row.push(first*second); break;}
		case '/':{row.push(first/second); break;}
		case '=':{row.push(second); break;}
		}
	}
	float res = row.pop();
	nums[Row[0]]=res;
	return res;
}