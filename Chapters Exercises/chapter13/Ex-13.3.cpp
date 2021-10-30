#include "iostream"
class ABC
{
    private:
    char *label;
    int rating;
    public:
    explicit ABC(const char * a="Null",const int b=0);
    ABC(const ABC &a);
    virtual ~ABC();
    ABC &operator=(const ABC &a);
    virtual void show()const =0;
};
class baseDMA : public ABC
{
  private:
    char *labe;

  public:
    baseDMA(const char *,const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    baseDMA(const ABC &,const char*);
    virtual ~baseDMA();
    baseDMA &operator=(const baseDMA &rs);
    virtual void show()const;
};
// derived class without DMA // no destructor needed // uses implicit copy constructor // uses implicit assignment operator
class lacksDMA : public ABC
{
  private:
    enum
    {
        COL_LEN = 40
    };
    char color[COL_LEN];

  public:
    lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
    lacksDMA(const char *c, const ABC &rs);
    virtual void show()const;
};
class hasDMA : public ABC
{
  private:
    char *style;
  public:
    hasDMA(const char *s = "none", const char *l = "null", int r = 0);
    hasDMA(const char *s, const ABC &rs);
    hasDMA(const hasDMA &hs);
    ~hasDMA();
    hasDMA &operator=(const hasDMA &rs);
    virtual void show()const;
};

const int CLIENTS = 4;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    ABC * p_clients[CLIENTS];
    char temp[40];
    char tempnum[40];
    int tempbal;
    char kind;
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter Label name: ";
        cin.getline(temp,40);
        cout << "Enter 2nd String ";
        cin.getline(tempnum,40);
        cout << "Enter rating: ";
        cin >> tempbal;
        cout << "Enter 1 for baseDMA:\n" << "Enter 2 for lackDMA:\nEnter 3 for hasDMA:\n";
        while (cin >> kind && (kind != '1' && kind != '2'&&kind!='3'))
        cout <<"Enter either 1 or 2 or 3: ";
        if (kind == '1')
        p_clients[i] = new baseDMA(temp, tempnum, tempbal);
        else if (kind == '2')
        p_clients[i] = new lacksDMA(temp, tempnum, tempbal);
        else
        {
           p_clients[i] = new hasDMA(temp, tempnum, tempbal);
         }
         while (cin.get() != '\n')
         continue;
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->show();
        cout << endl;
     }
     for (int i = 0; i < CLIENTS; i++)
     {
         delete p_clients[i];  // free memory
     }
     cout << "Done.\n";
     return 0;
}
ABC::ABC(const char * a, const int b)
{
    label = new char[std::strlen(a) + 1];
    std::strcpy(label, a);
    rating = b;
}
ABC::ABC(const ABC & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}
ABC::~ABC()
{
    delete[] label;
}
ABC &ABC::operator=(const ABC &rs)
{
    if (this == &rs)
        return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}
void ABC::show() const
{
    std::cout<<"Label: " << label << std::endl;
    std::cout<<"Rating: " << rating << std::endl;  
}
baseDMA::baseDMA(const char* la,const char *l, int r): ABC(l,r)
{
    labe = new char[std::strlen(l) + 1];
    std::strcpy(labe, l);
}
baseDMA::baseDMA(const baseDMA &rs):ABC(rs)
{
    labe = new char[std::strlen(rs.labe) + 1];
    std::strcpy(labe, rs.labe);
}
baseDMA::~baseDMA() { delete[] labe; }
baseDMA &baseDMA::operator=(const baseDMA &rs)
{
    if (this == &rs)
        return *this;
    delete[] labe;
    ABC::operator=(rs);
    labe = new char[std::strlen(rs.labe) + 1];
    std::strcpy(labe, rs.labe);
    return *this;
}
void baseDMA::show() const
{
    std::cout<<"baseDMA::show(): " <<std::endl;
    ABC::show();
    std::cout<<"String: " << labe << std::endl;  
}
lacksDMA::lacksDMA(const char *c, const char *l, int r) : ABC(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}
lacksDMA::lacksDMA(const char * c, const ABC & rs) : ABC(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}
void lacksDMA::show() const
{
    std::cout<<"lacksDMA::show(): " <<std::endl;
    ABC::show();
    std::cout<< "Color: " << color << std::endl;  
}
hasDMA::hasDMA(const char *s, const char *l, int r) : ABC(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const char *s, const ABC &rs) : ABC(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &hs) : ABC(hs) // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}
hasDMA::~hasDMA() { delete[] style; }
hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    ABC::operator=(hs); // copy base portion
    delete[] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
void hasDMA::show() const
{
    std::cout<<"haseDMA::show(): " <<std::endl;
    ABC::show();
    std::cout<< "Style: " << style << std::endl;
}
