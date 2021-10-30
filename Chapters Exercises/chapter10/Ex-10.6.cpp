#include "iostream"

class Move
{ 
    private:
    double x;
    double y;
    public:
    Move(double a = 0, double b = 0){x=a;y=b;};   // sets x, y to a, b 
    void showmove() const;                   // shows current x, y values 
    Move add(const Move & m) const; // this function adds x of m to x of invoking object to get new x, // adds y of m to y of invoking object to get new y, creates a new // move object initialized to new x, y values and returns it 
    void reset(double a = 0, double b = 0);  // resets x,y to a, b 
    };

using namespace std;
 
int main()
{
	Move a1(54,76);
	cout<<"#a1 : ";
	a1.showmove();
	Move a2;
	a2=Move(22,6);
	cout<<"#a2 : ";
	a2.showmove();
	Move a3=a1.add(a2);
	cout<<"#a3 : ";
	a3.showmove();
	cout<<"#a2 : ";
	a1.showmove();
	a3.reset();
	cout<<"#a3 : ";
	a3.showmove();
	
	
}
void Move::showmove() const
{
    cout<<"x = "<<x<<" y = "<<y<<endl;
}
Move Move::add(const Move & m) const
{
   double newX = x + m.x;
    double newY = this->y + m.y;

    return Move(newX, newY);
}
void Move::reset(double a, double b)
{
    x=a;
    y=b;
}