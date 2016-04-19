#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int n,m;
	while(scanf("%d %d", &n, &m) == 2 && (m-n) >= 0)
	{
		int *num = new int[m-n+1];
		for(int i=0; i<m-n+1; i++)
		{
			num[i] = i+n;
		}

		int divid;
		for(int i=0; i<m-n+1; i++)
		{
			if(num[i] != 0)
			{
				if(num[i] <= 1)
					;
				else
				{
					for(divid = 2; divid <= sqrt(double(num[i])); divid++)
					{
						if(num[i] % divid == 0)
							break;
					}
					if(divid > sqrt(double(num[i])))    // num[i] is a prime
					{
						cout << num[i] << endl;
						if(num[i] <= sqrt(double(m)))
						{
							for(int j= num[i] * num[i]; j<=m; j += num[i])
								num[j-n] = 0;				
						}
					}
					else
					{
						int temp = num[i];
						num[i] = 0;
						for(int j = temp + divid; j<=m; j += divid)
							num[j-n] = 0;
					}

				}
			}
		}

		delete [] num;
		cout << endl;
	
	}
	return 0;
	
}
