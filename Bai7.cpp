#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
	Time(int h, int m, int s)
	{
		if (h < 0 || h >= 24 )
		{
			cout << "Wrong hour\n";
		}
		if (m < 0 || m >= 60)
		{
			cout << "Wrong minute\n";
		}
		if (s < 0 || s >= 60)
		{
			cout << "Wrong second\n";
		}
		else if(h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
		{
			hour = h;
			minute = m;
			second = s;
		}
	}

	~Time(){}

	void display()
	{
		string h, m, s;

		h += to_string(hour);
		if (hour < 10)
		{
			h.insert(0, 1, '0');
		}

		m += to_string(minute);
		if (minute < 10)
		{
			m.insert(0, 1, '0');
		}

		s += to_string(second);
		if (second < 10)
		{
			s.insert(0, 1, '0');
		}

		cout << h << ":" << m << ":" << s << endl;
	}

	void setTime(int h, int m, int s)
	{
		if (h < 0 || h >= 24)
		{
			cout << "Wrong hour\n";
		}
		if (m < 0 || m >= 60)
		{
			cout << "Wrong minute\n";
		}
		if (s < 0 || s >= 60)
		{
			cout << "Wrong second\n";
		}
		else if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
		{
			hour = h;
			minute = m;
			second = s;
		}
	}

	void setHour(int h)
	{
		if (h < 0 || h >= 24)
		{
			cout << "Wrong hour\n";
		}
		else
		{
			hour = h;
		}
	}
	int getHour()
	{
		return hour;
	}

	void setMinute(int m)
	{
		if (m < 0 || m >= 60)
		{
			cout << "Wrong minute\n";
		}
		else
		{
			minute = m;
		}
	}
	int getMinute()
	{
		return minute;
	}

	void setSecond(int s)
	{
		if (s < 0 || s >= 60)
		{
			cout << "Wrong second\n";
		}
		else
		{
			second = s;
		}
	}
	int getSecond()
	{
		return second;
	}

	void prevSecond()
	{
		if (hour == 0 && minute == 0 && second == 0)
		{
			hour = 23;
			minute = 59;
			second = 59;
			return;
		}
		if (minute == 0 && second == 0)
		{
			hour--;
			minute = 59;
			second = 59;
			return;
		}
		if (second == 0)
		{
			minute--;
			second = 59;
			return;
		}
		second--;
	}

	void nextSecond()
	{
		if (hour == 23 && minute == 59 && second == 59)
		{
			hour = 0;
			minute = 0;
			second = 0;
			return;
		}
		if (minute == 59 && second == 59)
		{
			hour++;
			minute = 0;
			second = 0;
		}
		if (second == 59)
		{
			minute++;
			second = 0;
			return;
		}
		second++;
	}
private:
	int hour, minute, second;
};

int main()
{
	Time a(13, 0, 0);
	a.display();

	a.setHour(23);
	a.display();

	a.setMinute(56);
	a.display();

	a.setSecond(59);
	a.display();

	a.nextSecond();
	a.display();

	a.prevSecond();
	a.display();
	return 0;
}