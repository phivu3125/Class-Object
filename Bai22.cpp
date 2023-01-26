#include <iostream>

using namespace std;

int a = 1;

class MyClass
{
public:
	MyClass();
	~MyClass();
}b, c, d, e;

MyClass::MyClass()
{
	cout << "Khoi dong " << a << endl;
	a++;
}

MyClass::~MyClass()
{
	cout << "Don dep" << endl;
}

int main()
{
	cout << "Hello, world.\n";
}
