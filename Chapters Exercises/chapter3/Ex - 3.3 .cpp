#include "iostream"

using namespace std;

int main()
{
    const float MinutToDegree_f = 60;
    const float SecToDegree_f = 3600;
    int degree, minut, sec;
    double MinutToDegree, SecToDegree, t_degree;
    cout << "Enter a latitude in degrees, minutes, and seconds:"<<endl;
    cout << "First, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minut;
    cout << "Finally, enter the seconds of arc: ";
    cin >> sec;
    MinutToDegree = minut/MinutToDegree_f;
    SecToDegree = sec/SecToDegree_f;
    t_degree = degree + MinutToDegree + SecToDegree;
    cout << degree << " degrees, " << minut << " minutes, " << sec << " seconds = " << t_degree << " degrees";
}