#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

/*
 *	2016Äê4ÔÂ15ÈÕ 16:31:42
 *	assume all operators and operands are just one character
 *	exp1: 9+6*5=39   postfix: 965*+
 *	exp2: ((3+7)*6-5)/5=11  postfix: 37+6*5-5/ 
 * */

int calculatePostfix(char *exp);
int calculate(int op1, int op2, char op);

int main()
{
	char c1[51] = "965*+";
	char c2[51] = "37+6*5-5/";

	cout << calculatePostfix(c1) << endl;  //39
	cout << calculatePostfix(c2) << endl;  //11
}


int calculatePostfix(char *exp)
{
	stack<int> s;
	int len = strlen(exp);
	for(int i=0; i<len; i++)
	{
		if(exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/')
			s.push(int(exp[i]) - 48);
		else
		{
			int op1 = s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			int result = calculate(op1,op2,exp[i]);
			s.push(result);
		}
	}
	return s.top();
}


int calculate(int op1, int op2, char op)
{
	if(op == '+')
		return (op1+op2);
	else if(op == '-')
		return (op2-op1);
	else if(op == '*')
		return (op1*op2);
	else if(op == '/' && op1 != 0)
		return (op2/op1);

	return 0;
}
