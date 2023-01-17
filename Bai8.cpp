#include <iostream>
#include <vector>
using namespace std;

class stack
{
public:
	void pop()
	{
		size--;
		int* temp = new int[size];
		copy(arr, arr + size, temp);
		delete[]arr;
		arr = new int[size];
		copy(temp, temp + size, arr);
	}

	void push(int x)
	{
		size++;
		int* temp = new int[size];
		copy(arr, arr + size, temp);
		temp[size - 1] = x;
		delete[]arr;
		arr = new int[size];
		copy(temp, temp + size, arr);
	}

	void isEmpty()
	{
		if (size == 0)
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			cout << "Stack is not empty" << endl;
		}
	}

	void disPlay()
	{
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				cout << arr[i] << "\n";
			}
			else
			{
				cout << arr[i] << "*";
			}
		}
	}

	stack()
	{
		arr = new int;
		size = 0;
	}
	~stack()
	{
		delete[]arr;
	}

	int Size()
	{
		return size;
	}

	int Top()
	{
		return top;
	}

private:
	int* arr;
	int size;
	int top;
};

bool checkPrim(int a)
{
	if (a == 2)
	{
		return 1;
	}
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int LargestPrimeNumber(int x)
{
	int max = 1;
	for (int i = 2; i <= x; i++)
	{
		if (checkPrim(i) == 1 && i > max && x % i == 0)
		{
			max = i;
		}
	}
	return max;
}
void intFactor(int x)
{
	cout << x << "=";
	stack s;
	int n = LargestPrimeNumber(x);
	while (x != 1)
	{
		s.push(n);
		x/= n;
		n = LargestPrimeNumber(x);
	}
	s.disPlay();
}

int main()
{
	intFactor(21219);
	return 0;
}