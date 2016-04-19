#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

void infixToPostfix(char *result, char *exp);
bool isLower(char a, char b);

int main()
{
	int num;
	if(scanf("%d", &num) == 1 && num >= 1 && num <= 100)
	{
		char **arr = new char *[num];
		for(int i=0; i<num; i++)
			arr[i] = new char[400];
		
		for(int i=0; i<num; i++)
			for(int j=0; j<400; j++)
				arr[i][j] = 0;

		char c[400];
		int count = 0;
		while(count < num && scanf("%s",c) == 1)
		{
			infixToPostfix(arr[count], c);
			count++;
		}

		for(int i=0; i<num; i++)
			cout << arr[i] << endl;

		for(int i=0; i<num; i++)
			delete(arr[i]);

		delete [] arr;
	}

	return 0;
}


void infixToPostfix(char *result, char *exp)
{
	int len = strlen(exp);
	int j=0;
	stack<char> s;
	int arrSize = 0;
	for(int i=0; i<len; i++)
	{
		if(isalpha(exp[i]))
		{
			result[j] = exp[i];
			j++;
		}
		else if(exp[i] == '(')
		{
			s.push(exp[i]);
		}
		else if(exp[i] == ')')
		{
			while(s.top() != '(')
			{
				result[j] = s.top();
				s.pop();
				j++;
			}
			s.pop();
		}
		else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
		{
			if( !s.empty() && s.top()!='(' && isLower(s.top(), exp[i]))
			{

				result[j] = s.top();
				j++;
				s.pop();
				s.push(exp[i]);
			}
			else
			{
				s.push(exp[i]);
			}
		}
	}
	while(!s.empty())
	{
		result[j] = s.top();
		s.pop();
		j++;
	}
}


bool isLower(char a, char b)
{
	/*
	 * 	 +, -, *, /, ^
	 * */
	int x1,x2;
	switch(a) 
	{
		case '+':
		{
			x1 = 0;
			break;
		}
		case '-':
		{
			x1 = 1;
			break;
		}
		case '*':
		{
			x1 = 2;
			break;
		}
		case '/':
		{
			x1 = 3;
			break;
		}
		case '^':
		{
			x1 = 4;
			break;
		}
		default: break;
	}

	switch(b) 
	{
		case '+':
		{
			x2 = 0;
			break;
		}
		case '-':
		{
			x2 = 1;
			break;
		}
		case '*':
		{
			x2 = 2;
			break;
		}
		case '/':
		{
			x2 = 3;
			break;
		}
		case '^':
		{
			x2 = 4;
			break;
		}
		default: break;
	}

	if(x2 - x1 <= 0)
		return true;
	else
		return false;
}
