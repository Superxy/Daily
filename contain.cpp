#include <iostream>
using namespace std;


int contain(char *a, char*b);

int main() 
{
	char a[8] = "contain";
	char b[4] = "ain";
	char c[4] = "ont";
	char d[4] = "tao";

	cout << contain(a,b) << endl;
	cout << contain(a,c) << endl;
	cout << contain(a,d) << endl;
	return 0;
}

int contain(char *a, char*b)
{
	while(*a != '0')
	{
		
		char *source = a;
		char *target = b;
		while(*source == *target && *source != '\0' && *target != '\0')
		{
			source++;
			target++;
		}
		if(*target == '\0')
			return 1;
		a++;
	}
	return 0;
}
