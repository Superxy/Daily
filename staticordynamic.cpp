#include <iostream>

using namespace std;

typedef  int(*func)(int, int);

int add(int a, int b)
{
	return a+b;
}

int substaction(int a, int b)
{
	return a-b;
}

int main()
{
	/*
	 * Static binding is when binding is known at compile time:
	 * */
	cout << add(4,5) << endl;

	/*
	 * whereas here, depending on the input, one gets either 9 or -1. This is dynamically bound.
	 * */
	char c;
	cin >> c;
	func f = (c == '+' ? &add : &substaction);
	cout << f(4,5) << endl;

	return 0;
}
