#include "iostream"
#include <iostream>

const int Max = 5;

// function prototypes
double *fill_array(double *, double *);
void show_array(const double *, const double *); // don't change data
void revalue(double r, double *, double *);

int main()
{
    using namespace std;

    double properties[Max];
    double *end = fill_array(properties, properties + Max);

    show_array(properties, end);

    if (end != properties)
    {
        cout << "Enter revaluation factor: ";

        double factor;

        while (!(cin >> factor))
        {
            cin.clear();

            while (cin.get() != '\n')
                continue;

            cout << "Bad input; Please enter a number: ";
        }

        revalue(factor, properties, end);
        show_array(properties, end);
    }

    cout << "Done.\n";
    cin.get();
    cin.get();

    return 0;
}

double *fill_array(double *begin, double *end)
{
    using namespace std;

    double *tmpPtr;
    double temp;
    int i = 1;

    for (tmpPtr = begin; tmpPtr != end; tmpPtr++)
    {
        cout << "Enter value #" << (i++) << ": ";
        cin >> temp;

        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;

            cout << "Bad input; input process terminated.\n";

            break;
        }
        else if (temp < 0)
            break;

        *tmpPtr = temp;
    }

    return tmpPtr;
}

void show_array(const double *begin, const double *end)
{
    using namespace std;

    const double *tmpPtr;
    int i = 1;

    for (tmpPtr = begin; tmpPtr != end; tmpPtr++)
    {
        cout << "Property #" << (i++) << ": $";
        cout << *tmpPtr << endl;
    }
}

void revalue(double r, double *begin, double *end)
{
    double *tmpPtr;

    for (tmpPtr = begin; tmpPtr != end; tmpPtr++)
        *tmpPtr *= r;
}