#include "iostream"
#include <cctype>

typedef unsigned long Item;
class Stack
{
    private:
    enum {MAX = 10};    // constant specific to class 
    Item * pitems;    // holds stack items
    int size;
    int top;            // index for top stack item 
    public:
    Stack(int n = MAX);    // creates stack with n elements
    Stack(const Stack & st);
    ~Stack();
    Stack & operator=(const Stack & st); 
    Stack(); 
    bool isempty() const; 
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item); 

};
 
int main()
{
    using namespace std;
    Stack st1(5);
    int x = 1;
    while(!st1.isfull())
        st1.push(x++);
    Stack st2 = st1;
    Stack st3(st2);
    Item val {};
    std::cout << "stack st1:\n";
    while(st1.pop(val))
        std::cout << val << '\n';
    std::cout << "stack st2:\n";
    while(st2.pop(val))
        std::cout << val << '\n';
    std::cout << "stack st3:\n";
    while(st3.pop(val))
        std::cout << val << '\n';
    Stack st(10); // create an empty stack 
    char ch; 
    unsigned long po; 
    cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n"; 
    while (cin >> ch && toupper(ch) != 'Q') 
    {
        while (cin.get() != '\n')
        continue;
        if (!isalpha(ch))
        {
            cout << "aaaa";
            continue; 
        }
        switch(ch)
        {
            case 'A':
            case 'a':
            cout << "Enter a PO number to add: "; cin >> po;
            if (st.isfull())
            cout << "stack already full\n";
            else st.push(po);
            break;
            case 'P':
            case 'p':
            if (st.isempty()) 
            cout << "stack already empty\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << " popped\n"; 
            }
            break;
        }
        cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";	
}
Stack::Stack(int n)    // create an empty stack 
{
    if(n < 0 || n > MAX)
    n=10;
    size=n;
    pitems=new Item[size];
    top = 0; 
}
Stack::Stack(const Stack & st)
{
    size=st.size;
    pitems=new Item[size];
    for(int i=0;i<size;i++)
    {
        pitems[i]=st.pitems[i];
    }
    top=st.top;
    
}
Stack::~Stack()
{
    delete []pitems;
}
Stack & Stack::operator=(const Stack & st)
{
    if (this==&st)
    return *this;
    delete []pitems;
    size=st.size;
    pitems=new Item[size];
    for(int i=0;i<size;i++)
    {
        pitems[i]=st.pitems[i];
    }
    top=st.top;
    return *this;
} 
bool Stack::isempty() const 
{ 
    return top == 0; 
} 
bool Stack::isfull() const 
{ 
    return top == size; 
} 
bool Stack::push(const Item & item) 
{
   // std::cout<<"push";
    if (top < size)
    {
        pitems[top++] = item;
        return true; 
    } 
    else return false; 
} 
bool Stack::pop(Item & item) 
{ 
    if (top > 0)
    { 
        item = pitems[--top]; 
        return true; 
    } 
    else return false; 
}