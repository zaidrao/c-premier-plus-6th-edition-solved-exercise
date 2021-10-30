#include "iostream"
#include "cstring"

const int Len = 40;

class golf
{
    private:
    char fullname[Len];
    int handicap;
    public:
    golf(const char *name="", int hc=0);
    int setgolf();
    void handica(int hc);
    void showgolf() const;
};

const int NUM_GOLF = 10;

using namespace std;

int main()
{
    golf golfers[NUM_GOLF];

    int numCollected = 0;

    for (int i = 0; i < NUM_GOLF; i++)
    {
        cout << "Golfer #" << i + 1 << endl;

        if (!(golfers[i].setgolf()))
        {
            break;
        }

        numCollected++;
    }

    cout << numCollected << " golfers were entered." << endl;

    for (int i = 0; i < numCollected; i++)
    {
        golfers[i].showgolf();
    }

    golf tiger;
    const char *name = "Tiger Woods";
    int hcap = 24;

    tiger=golf(name, hcap);

    tiger.showgolf();
    tiger.handica(25);
    tiger.showgolf();
}
golf::golf(const char *name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

int golf::setgolf()
{
    char fn[Len];
    int hc;
    std::cout << "Enter name: ";
    std::cin.getline(fn, Len);

    std::cout << "Enter handicap: ";
    (std::cin >> hc).get();
    *this=golf(fn,hc);
    return strlen(fn) == 0 ? 0 : 1;
}

void golf::handica(int hc)
{
    handicap = hc;
}

void golf::showgolf() const
{
    std::cout << "Name: " <<fullname << std::endl;
    std::cout << "Handicap: " <<handicap << std::endl;
}
