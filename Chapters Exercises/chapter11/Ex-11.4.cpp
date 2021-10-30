#include "iostream"

class Time
{
  private:
    int hours;
    int minutes;

  public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator+(const Time &t, const Time &ti);
    friend Time operator-(const Time &t,const Time &ti);
    friend Time operator*(const Time &t,double n);
    friend Time operator*(double m, const Time &t) { return t * m; } // inline definition
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
};

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca; // operator+()
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17; // member operator*()
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
}

Time::Time()
{
    hours = minutes = 0;
}
Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}
void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void Time::AddHr(int h)
{
    hours += h;
}
void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}
Time operator+(const Time &t, const Time &ti)
{
    Time sum;
    sum.minutes = ti.minutes + t.minutes;
    sum.hours = ti.hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
Time operator-(const Time &t,const Time &ti)
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = ti.minutes + 60 * ti.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}
Time operator*(const Time &t,double mult)
{
    Time result;
    long totalminutes = t.hours * mult * 60 + t.minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
std::ostream &operator<<(std::ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}