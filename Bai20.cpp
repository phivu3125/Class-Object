#include <iostream>
#include <math.h>

using namespace std;

class Circle
{
public:
	void pointInCir(float a, float b)
	{
		float temp = sqrt(pow(x - a, 2) + pow(y - b, 2));
		if (temp == r )
		{
			cout << "Diem nay nam tren hinh tron\n";
			return;
		}
		if (temp < r)
		{
			cout << "Diem nay nam trong hinh tron\n";
			return;
		}
		cout << "Diem nay nam ben ngoai hinh tron\n";
	}
	void isIntersect(Circle b)
	{
		float temp = sqrt(pow(this->x - b.x, 2) + pow(this->y - b.y, 2));
		float sumR = this->r + b.r;
		if (sumR == temp)
		{
			cout << "2 hinh tron giao nhau tai 1 diem\n";
			return;
		}
		if (sumR > temp)
		{
			cout << "2 hinh tron giao nhau tai 2 diem\n";
			return;
		}
		cout << "2 hinh tron khong giao nhau\n";
	}
	Circle()
	{
		cout << "Nhap toa do x: ";
		cin >> x;
		cout << "Nhap toa do y: ";
		cin >> y;
		cout << "Nhap ban kinh: ";
		cin >> r;
	}
	~Circle(){}
private:
	float x, y, r;
};

int main()
{
	Circle a, b;
	a.pointInCir(0, 0);
	a.isIntersect(b);
	return 0;
}