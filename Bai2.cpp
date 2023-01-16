#include <iostream>
#include <cctype>
#include <string>
#include <math.h>
using namespace std;

void removeSpace(string& s)
{
	s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
}

int UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else if (a < b)
		{
			b -= a;
		}
	}
	return a;
}
class PhanSo
{
public:
	void inPut()
	{
		string s;
		getline(cin, s);
		removeSpace(s);
		int pos = 0;
		if (s[0] == '/')
		{
			cout << "Nhap sai\n";
			return;
		}
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '/')
			{
				string temp = s.substr(0, i - 1);
				tu = stoi(s);
				pos = i;
				break;
			}
		}
		string temp = s.substr(pos + 1, s.size() - pos);
		mau = stoi(temp);
	}
	void doiDau()
	{
		if (tu * mau > 0)
		{
			tu = abs(tu);
			mau = abs(mau);
		}
		else if(tu * mau < 0)
		{
			if (mau < 0)
			{
				tu = 0 - tu;
				mau = 0 - mau;
			}
		}
	}
	void outPut()
	{
		if (mau == 0)
		{
			cout << "phan so khong ton tai\n";
		}
		else if(tu == 0)
		{
			cout << tu << endl;
		}
		else
		{
			doiDau();
			cout << tu << "/" << mau << endl;
		}
	}

	PhanSo operator +(PhanSo b)
	{
		PhanSo res;
		res.tu = this->tu * b.mau + this->mau * b.tu;
		res.mau = this->mau * b.mau;
		return res;
	}

	PhanSo operator -(PhanSo b)
	{
		PhanSo res;
		res.tu = this->tu * b.mau - this->mau * b.tu;
		res.mau = this->mau * b.mau;
		return res;
	}

	PhanSo operator *(PhanSo b)
	{
		PhanSo res;
		res.tu = this->tu * b.tu;
		res.mau = this->mau * b.mau;
		return res;
	}

	PhanSo operator /(PhanSo b)
	{
		PhanSo res;
		res.tu = this->tu * b.mau;
		res.mau = this->mau * b.tu;
		return res;
	}
	void rutGon()
	{
		int ucln = UCLN(abs(tu), abs(mau));
		tu /= ucln;
		mau /= ucln;
	}

private:
	int tu;
	int mau;
};

int main()
{
	PhanSo a, b;
	char op;
	cout << "Nhap phan so thu 1:";
	a.inPut();
	a.rutGon();
	a.outPut();
	cout << "Nhap phan so thu 2:";
	b.inPut();
	b.rutGon();
	b.outPut();
	cout << "Nhap phep toan muon tinh:";
	cin >> op;
	switch (op)
	{
		case '+':
		{
			PhanSo res = a + b;
			res.rutGon();
			res.outPut();
			break;
		}
		case '-':
		{
			PhanSo res = a - b;
			res.rutGon();
			res.outPut();
			break;
		}
		case '*':
		{
			PhanSo res = a * b;
			res.rutGon();
			res.outPut();
			break;
		}
		case '/':
		{
			PhanSo res = a / b;
			res.rutGon();
			res.outPut();
			break;
		}
	}
	return 0;
}