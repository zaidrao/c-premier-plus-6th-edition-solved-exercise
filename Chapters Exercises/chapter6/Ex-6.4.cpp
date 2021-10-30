#include "iostream"

using namespace std;

const int strsize = 40;
struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
}; // 0 = fullname, 1 = title, 2 = bopname };

int main()
{
    bop emp[4] =
        {
            {"Ali", " Director", "Alid", 1},
            {"Zafar", "DPTY", "Zad", 0},
            {"Nabeel", " ACP", "Nac", 2},
            {"Bol", "TTRP", "Bot", 1}

        };
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "\na. display by name     b. display by title\nc. display by bopname  d. display by preference\nq. quit" << endl;
    char ch;
    cout << "Enter your choice: ";
    cin >> ch;
    while (ch != 'q')
    {
        switch (ch)
        {
        case 'a':
            for (int i = 0; i < 4; i++)
                cout << emp[i].fullname << endl;
            break;
        case 'b':
            for (int i = 0; i < 4; i++)
                cout << emp[i].title << endl;
            break;
        case 'c':
            for (int i = 0; i < 4; i++)
                cout << emp[i].bopname << endl;
            break;
        case 'd':
            for (int i = 0; i < 4; i++)
            {
                if (emp[i].preference == 1)
                    cout << emp[i].title << endl;
                else if (emp[i].preference == 0)
                    cout << emp[i].fullname << endl;
                else
                    cout << emp[i].bopname << endl;
            }
            break;
        default:
            cout << "Input carefully." << endl;
            break;
        }

        cout << "Enter your choice: ";
        cin >> ch;
    }
    cout << "Bye!";
}