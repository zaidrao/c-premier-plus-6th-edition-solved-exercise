#include <iostream>

namespace chp10
{
typedef unsigned long Item;

class List
{
    struct node
    {
        Item item;
        node *next;
    };

    int size_;
    int capacity_;
    node *tail_;
    node *head_;

  public:
    List(int capacity = 10);
    ~List();
    int size();
    void add(Item);
    bool isEmpty();
    void visit(void (*pf)(Item &));
};
}
void showItem(chp10::Item &item);
void populateList(chp10::List &list, int numItems);

int main()
{
    using chp10::List;

    List list;

    // Capacity of the list is 10. Try adding 11 items.
    populateList(list, 11);

    std::cout << "Items in List list: " << std::endl;

    list.visit(showItem);

    List list2(1000);

    populateList(list2, 10);

    std::cout << "Items in List list2: " << std::endl;

    list2.visit(showItem);

    return 0;
}

void showItem(chp10::Item &item)
{
    std::cout << item << std::endl;
}

void populateList(chp10::List &list, int numItems)
{
    std::cout << "Size before add items: " << list.size() << std::endl;

    for (int i = 0; i < numItems; i++)
    {
        list.add(i);
    }

    std::cout << "Size after add items: " << list.size() << std::endl;
}
namespace chp10
{
List::List(int capacity)
{
    this->capacity_ = capacity;
    this->size_ = 0;
    this->head_ = new node;
    this->tail_ = this->head_;
}

List::~List()
{
    if (this->size_ == 0)
    {
        delete this->head_;
    }

    node *current = this->head_;

    while (current != 0)
    {
        node *next = current->next;

        delete current;

        current = next;
    }
}

int List::size()
{
    return this->size_;
}

void List::add(Item item)
{
    if (this->size_ < this->capacity_)
    {
        if (this->size_ > 0)
        {
            this->tail_->next = new node;
            this->tail_ = this->tail_->next;
        }

        this->tail_->item = item;

        this->size_++;
    }
}

bool List::isEmpty()
{
    return this->size_ == 0;
}

void List::visit(void (*pf)(Item &))
{
    if (this->size_ > 0)
    {
        node current = *this->head_;

        for (int i = 0; i < this->size_; i++)
        {
            (*pf)(current.item);

            if (current.next != NULL)
            {
                current = *current.next;
            }
        }
    }
}
}