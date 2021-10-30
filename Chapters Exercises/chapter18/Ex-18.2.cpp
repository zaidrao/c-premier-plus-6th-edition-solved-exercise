#include <iostream>

class Cpmv
{
  public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
  private:
	Info *pi;
  public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv &cp);
	Cpmv(Cpmv &&mv);
	~Cpmv(){delete pi;}
	Cpmv &operator=(const Cpmv &cp);
	Cpmv &operator=(Cpmv &&mv);
	Cpmv operator+(const Cpmv &obj) const;
	void Display() const;
};

int main()
{
	using namespace std;
	string q = "Hello";
	string z = "this is string";
	Cpmv obj1(q,z);
	cout<<"obj1\n";
	obj1.Display();
	Cpmv obj2 = obj1;
	Cpmv obj3(obj1+obj2);
	cout<<"obj2\n";
	obj2.Display();
	cout<<"obj3\n";
	obj3.Display();
	
}

Cpmv::Cpmv()
{
	pi = new Info;
}

Cpmv::Cpmv(std::string q, std::string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv &cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv &&mv)
{
	pi = mv.pi;
	mv.pi = NULL;
}

Cpmv &Cpmv::operator=(const Cpmv &cp)
{
	if(&cp == this)
	return *this;
	
	delete pi; 
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}

Cpmv &Cpmv::operator=(Cpmv &&mv)
{
	if(&mv == this)
	return *this;
	
	delete pi;
	pi = new Info;
	pi = mv.pi;
	mv.pi = NULL;
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
	Cpmv temp = Cpmv(*this);
	temp.pi->qcode += obj.pi->qcode;
	temp.pi->zcode += obj.pi->zcode;
	return temp;
}

void Cpmv::Display() const
{
	std::cout<<"qcode: "<<pi->qcode<<std::endl;
	std::cout<<"zcode: "<<pi->zcode<<std::endl;
}