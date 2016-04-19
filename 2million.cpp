#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() 
{
	char ch[2000000];
	memset(ch,'1', sizeof(ch));

	for(int i=2; i<=sqrt(double(2000000)); i++)
	{
		if(ch[i] == '1')
		{
			for(int j=i *i; j<2000000; j += i)
				ch[j] = '0';
		}
	}

	unsigned long long int sum = 0;
	for(int i=2; i<2000000; i++)
	{
		if(ch[i] == '1')
			sum += i;
	}

	cout << sum << endl;

	return 0;
}
