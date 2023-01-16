#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Complex
{
public:
	void inPut()
	{
		cout << "Nhap phan thuc: ";
		cin >> real;
		cout << "Nhap phan ao: ";
		cin >> img;
	}
	void output()
	{
		if (real == 0 && img != 0)
		{
			cout << img << "i" << endl;
		}
		else
		{
			if (img < 0)
			{
				cout << real << img << "i" << endl;
			}
			else if (img == 0)
			{
				cout << real << endl;
			}
			else if (img > 0)
			{
				cout << real << "+" << img << "i" << endl;
			}
		}
	}

	Complex operator +(Complex b)
	{
		Complex res;
		res.real = this->real + b.real;
		res.img = this->img + b.img;
		return res;
	}

	Complex operator -(Complex b)
	{
		Complex res;
		res.real = this->real + -b.real;
		res.img = this->img - b.img;
		return res;
	}

	Complex operator *(Complex b)
	{
		Complex res;
		res.real = (this->real* b.real) - (this->img * b.img);
		res.img = (this->real * b.img) + (this->img * b.real);
		return res;
	}

	Complex operator /(Complex b)
	{
		Complex res;
		res.real = ((this->real * b.real) + (this->img * b.img)) / (pow(this->real, 2) + pow(this->img,2));
		res.img = ((this->real * b.img) - (this->img * b.real)) / (pow(this->real, 2) + pow(this->img, 2));
		return res;
	}
private:
	float real, img;
};

int main()
{
	char op;
	Complex c1, c2;
	cout << "Nhap so phuc thu 1\n";
	c1.inPut();
	c1.output();
	cout << "Nhap so phuc thu 2\n";
	c2.inPut();
	c2.output();
	cout << "Chon toan tu: ";
	cin >> op;
	switch (op)
	{
		case '+':
		{
			(c1 + c2).output();
			break;
		}
		case '-':
		{
			(c1 - c2).output();
			break;
		}
		case '*':
		{
			(c1 * c2).output();
			break;
		}
		case '/':
		{
			(c1 / c2).output();
			break;
		}
		default:
		{
			cout << "Nhap sai toan tu\n";
			break;
		}
	}
	return 0;
}