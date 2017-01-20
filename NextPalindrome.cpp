#include <iostream>
#include <cstring>
#include <cstdio>

/*
	recieve Palindrome in exp
	return least greater Palindrome in result.
*/
void NextPalindrome(char result[], char exp[]);
bool IsOddPalindrome(char exp[]);
bool IsOddGreater(char exp[]);
bool AllNine(char exp[], int index1, int index2);
bool AllZero(char exp[]);
bool IsEvenPalindrome(char exp[]);
bool IsEvenGreater(char exp[]);
void DeleteZero(char exp[]);


void NextPalindrome(char result[], char exp[])
{
	int length = strlen(exp);
	// case 1: odd number
	int i=0, j=0;
	if(length % 2 != 0)
	{
		int mid = length / 2;
		//case a: length >= 3
		if(mid - 1 >= 0 && length - 1 >= mid+1)
		{
			if(IsOddPalindrome(exp))
			{
				if(AllZero(exp))
				{
					exp[mid] = exp[mid] + 1;
					strncpy(result, exp, length);
					return;
				}
				// 999 -> 1001  99999->100001
				if(AllNine(exp, 0, mid))
				{
					int max = (mid+1) * 2;
					result[0] = '1';
					result[max-1] = '1';
					for(i=1; i<max-1; i++)
						result[i] = '0';
					return;
				}
				else
				{
					for(i=mid; i>=0; i--)
					{
						if(exp[i] != '9')
							break;
					}
					// 878 -> 888  809989908->809999908
					if(i == mid)
					{
						exp[i] = exp[i] + 1;
						strncpy(result, exp, length);
						return;
					}
					// 898 -> 909 809999908->810000018
					else
					{
						exp[i] = exp[i] + 1;
						for(j = i+1; j<= mid; j++)
							exp[j] = '0';
						for(j = 0; j < mid; j++)
							exp[length-1-j] = exp[j];
						strncpy(result, exp, length);
						return;
					}
				}
			}
			// 87615 -> 87678
			if(IsOddGreater(exp))
			{
				for(i=0; i<mid; i++)
					exp[length-1-i] = exp[i];
				strncpy(result, exp, length);
				return;
			}
			// 87679 -> 87778
			else
			{
				for(i=mid; i>=0; i--)
				{
					if(exp[i] != '9')
						break;
				}
				// 87679 -> 87778
				if(i == mid)
				{
					exp[i] = exp[i] + 1;
					for(j = 0; j < mid; j++)
						exp[length-1-j] = exp[j];
					strncpy(result, exp, length);
					return;
				}
				// 87979 -> 88088
				else
				{
					exp[i] = exp[i] + 1;
					for(j = i+1; j<= mid; j++)
						exp[j] = '0';
					for(j = 0; j < mid; j++)
						exp[length-1-j] = exp[j];
					strncpy(result, exp, length);
					return;
				}
			}
		}
		//case b: length = 1
		else
		{
			if(exp[mid] == '9')
			{
				result[0] = '1';
				result[1] = '1';
				return;
			}
			else
			{
				result[0] = exp[mid] + 1;
				return;
			}
		
		}
	}
	// case 2: even number
	else
	{
		int mid = length / 2 - 1;
		if(IsEvenPalindrome(exp))
		{
			// 99 -> 101
			if(AllNine(exp, 0, mid))
			{
				int max = length + 1;
				result[0] = '1';
				result[max-1] = '1';
				for(j=1; j<max-1; j++)
					result[j] = '0';
				return;
			}
			// 9889 -> 9999  8998-> 9009
			else
			{
				for(i=mid; i>=0; i--)
				{
					if(exp[i] != '9')
						break;
				}
				exp[i] = exp[i] + 1;
				for(j=i+1; j<= mid; j++)
					exp[j] = '0';
				for(j=0; j<= mid; j++)
					exp[length-1-j] = exp[j];
				strncpy(result, exp, length);
					return;
			}
		}
		// 9887 -> 9889
		if(IsEvenGreater(exp))
		{
			for(i=0; i<= mid; i++)
				exp[length-1-i] = exp[i];
			strncpy(result, exp, length);
			return;
		}
		// 9789 -> 9889
		else
		{
			for(i=mid; i>=0; i--)
			{
				if(exp[i] != '9')
					break;
			}
			exp[i] = exp[i] + 1;
			for(j=i+1; j<= mid; j++)
				exp[j] = '0';
			for(j=0; j<= mid; j++)
				exp[length-1-j] = exp[j];
			strncpy(result, exp, length);
				return;
		}
	}
}

bool IsOddPalindrome(char exp[])
{
	int length = strlen(exp);
	int mid = length / 2;
	int i;
	for(i=0; i<mid; i++)
	{
		if(exp[i] != exp[length-1-i])
			break;
	}
	if(i == mid)
		return true;
	else
		return false;
}

bool AllNine(char exp[], int index1, int index2)
{
	int i;
	for(i = index1; i <= index2; i++)
	{
		if(exp[i] != '9')
			break;
	}
	if(i == index2 + 1)
		return true;
	else 
		return false;
}

bool IsOddGreater(char exp[])
{
	int length = strlen(exp);
	int mid = length / 2;
	int i;
	for(i=0; i<mid; i++)
	{
		if(exp[i] - exp[length-1-i] < 0)
			break;
	}
	if(i == mid)
		return true;
	else
		return false;
}

bool IsEvenPalindrome(char exp[])
{
	int length = strlen(exp);
	int mid = length / 2 - 1;
	int i;
	for(i =0; i<= mid; i++)
	{
		if(exp[i] != exp[length - 1 - i])
			break;
	}
	if(i == mid + 1)
		return true;
	else
		return false;
}

bool IsEvenGreater(char exp[])
{
	int length = strlen(exp);
	int mid = length / 2 - 1;
	int i;
	for(i = 0; i<= mid; i++)
	{
		if(exp[i] - exp[length - 1 - i] < 0)
			break;
	}
	if(i == mid + 1)
		return true;
	else 
		return false;
}

void DeleteZero(char exp[])
{
	while(exp[0] == '0')
	{
		int length = strlen(exp);
		for(int i=0; i<length; i++)
		{
			exp[i] = exp[i+1];
		}
	}
}

bool AllZero(char exp[])
{
	int length = strlen(exp);
	int i;
	for(i = 0; i< length; i++)
	{
		if(exp[i] != '0')
			break;
	}
	if(i == length)
		return true;
	else
		return false;
}


int main()
{
	int num;
	int count = 0;
	int i,j;
	std::cin >> num;
	if(num >= 1)
	{
		char **arr = new char *[num];
		for(i=0; i<num; i++)
			arr[i] = new char[1000000];
		
		for(i=0; i<num; i++)
			for(int j=0; j<1000000; j++)
				arr[i][j] = 0;


		char exp[1000000];
		memset(exp, 0, sizeof(exp));
		while(count < num)
		{
			std::cin >> exp;
			if(!AllZero(exp))
				DeleteZero(exp);
			NextPalindrome(arr[count], exp);
			std::cout << arr[count] << std::endl;
			count++;
		}

		for(i = 0; i < num; i++)
			delete [] arr[i];

		delete [] arr;
	}

	return 0;
}
