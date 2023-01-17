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
		for (int i = size - 1 ; i >= 0; i--)
		{
			if (i == 0)
			{
				cout << arr[i];
			}
			else
			{
				cout << arr[i] << "+";
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

	int sum()
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}
private:
	int* arr;
	int size;
	int top;
};

stack sumDigit(int x)
{
	stack s;
	int n = 0;
	while (x != 0)
	{
		n = x % 10;
		s.push(n);
		x /= 10;
	}
	return s;
}

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;
	stack s = sumDigit(n);
	s.disPlay();
	cout << " = " << s.sum();
	return 0;
}