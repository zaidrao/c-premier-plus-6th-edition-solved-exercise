#include "iostream"
#include <cctype>

struct customer
{
    char fullname[35]; 
    double payment; 
    };

typedef customer Item;
class Stack
{
  private:
    enum
    {
        MAX = 10
    };               // constant specific to class
    Item items[MAX]; // holds stack items
    int top;         // index for top stack item
  public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
};

int main()
{
    using namespace std;
    Stack st; // create an empty stack
    char ch;
    customer po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << "aaaa";
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
            cout << "Enter a customer name: ";
            cin>>po.fullname;
            cout << "Enter a Payment to add: ";
            cin >> po.payment;
            if (st.isfull())
                cout << "stack already full\n";
            else
                st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(po);
                cout << "Payment " << po.payment << "£ popped from "<<po.fullname<<"\n";
            }
            break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
}
Stack::Stack() // create an empty stack
{
    top = 0;
}
bool Stack::isempty() const
{
    return top == 0;
}
bool Stack::isfull() const
{
    return top == MAX;
}
bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}
bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}