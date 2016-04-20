#include <iostream>

using namespace std;


/*
 *The user-defined function called operator++ implements the prefix and postfix ++ operator.
 *If this function is a member function with no parameters, or a non-member function with one 
 *parameter of class or enumeration type, it defines the prefix increment operator ++ for objects 
 *of that type. If the function is a member function with one parameter (which shall be of type int) 
 *or a non-member function with two parameters (the second of which shall be of type int), 
 *it defines the postfix increment operator ++ for objects of that type. When the postfix increment 
 *is called as a result of using the ++ operator, the int argument will have value zero.125)
 *
 *
 * */

class Digit
{
private:
	int m_digit;
public:
	explicit Digit(int i) : m_digit(i) {}
	Digit & operator++();
	Digit operator++(int);
	friend ostream & operator <<(ostream &os, const Digit &d)
	{
		os << d.m_digit;
		return os;
	}
};

Digit & Digit::operator++()
{
	++m_digit;
	return (*this);
}

Digit Digit::operator++(int)
{
	Digit d(m_digit);
	++(*this);
	return d;
}

int main()
{
	Digit d(5);
	cout << d << endl;
	cout << ++d << endl;
	cout << d++ << endl;
	cout << d << endl;
	return 0;
}
