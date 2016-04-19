#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

/*
 *	2016Äê4ÔÂ15ÈÕ 11:27:45
 *	Using stack to check whether the expression is parentheses balanced?
 * */

bool isBalanced(char *exp);

int main()
{
	char c[51];
	scanf("%s", c);
	cout << isBalanced(c);

	return 0;
}


bool isBalanced(char *exp)
{
	stack<char> s;
	int len = strlen(exp);
	for(int i=0; i<len; i++)
	{
		if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			s.push(exp[i]);
		else if(exp[i] == '}')
		{
			if(s.empty() || s.top() != '{')
				return false;
			else
				s.pop();
		}
		else if(exp[i] == ')')
		{
			if(s.empty() || s.top() != '(')
				return false;
			else
				s.pop();
		}	
		else if(exp[i] == ']')
		{
			if(s.empty() || s.top() != '[')
				return false;
			else
				s.pop();
		}
	}
	if( s.empty() )
		return true;
	else
		return false;
}
