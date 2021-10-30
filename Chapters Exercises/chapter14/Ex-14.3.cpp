#include "iostream"

template <class Item>
class QueueTP
{
  private: // class scope definitions // Node is a nested structure definition local to this class
    struct Node
    {
        Item item;
        struct Node *next;
    };
    enum
    {
        Q_SIZE = 10
    };               // private class members
    Node *front;     // pointer to front of Queue
    Node *rear;      // pointer to rear of Queue
    int items;       // current number of items in Queue
    const int qsize; // maximum number of items in Queue // preemptive definitions to prevent public copying
    QueueTP(const QueueTP &q) : qsize(0) {}
    QueueTP &operator=(const QueueTP &q) { return *this; }

  public:
    QueueTP(int qs = Q_SIZE) :front(NULL), rear(nullptr), items (0), qsize(qs){} // create queue with a qs limit
    ~QueueTP();
    bool isempty() const{return items == 0;}
    bool isfull() const{return items == qsize;}
    int queuecount() const{return items;}
    bool enqueue(const Item &item); // add item to end
    bool dequeue(Item &item);       // remove item from front
};

class Worker   
{
    private:
    std::string fullname;
    long id;
    public:
    virtual void Data() const;
    virtual void Get();
    Worker() : fullname("no one"), id(0L) {} 
    Worker(const std::string & s, long n) : fullname(s), id(n) {}
    virtual ~Worker(){}
};
 
int main()
{
	using std::string;
	using std::cin;
	using std::cout;
	QueueTP<Worker*> w(2);
	while(!w.isfull())
	{
	    Worker* temp=new Worker;
	    cout << "Please enter your name and ID. You will be " "served in the order of arrival.\n" "name: ";
	    temp->Get();
	    w.enqueue(temp);
	    
	 }
	 cout << "The queue is full. Processing begins!\n";
	 while (!w.isempty())
	 {
	     Worker* temp=new Worker;
	     w.dequeue(temp);
	     cout << "Now processing....\n ";
	     temp->Data(); 
	     delete temp;
	 }
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
    Node *temp;
    while (front != NULL) // while queue is not yet empty
    {
        temp = front;        // save address of front item
        front = front->next; // reset pointer to next item
        delete temp;         // delete former front
    }
}
template <class Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
    if (isfull())
        return false;
    Node *add = new Node; // create node // on failure, new throws std::bad_alloc exception
    add->item = item;     // set node pointers
    add->next = NULL;     // or nullptr;
    items++;
    if (front == NULL) // if queue is empty,
        front = add;   // place item at front
    else
        rear->next = add; // else place at rear
    rear = add;           // have rear point to new node
    return true;
} // Place front item into item variable and remove from queue
template <class Item>
bool QueueTP<Item>::dequeue(Item &item)
{
    if (front == NULL)
        return false;
    item = front->item; // set item to first item in queue
    items--;
    Node *temp = front;  // save location of first item
    front = front->next; // reset front to next item
    delete temp;         // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}
void Worker::Data() const
{
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}
void Worker::Get()
{
    getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n')
    continue;
}