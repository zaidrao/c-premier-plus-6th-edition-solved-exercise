#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// functor to store data in file
class Store
{
	private:
	std::ofstream &out;
	public:
	Store(std::ofstream &ou):out(ou){}
	void operator () (const std::string &);
	
};
// show string data
void ShowStr(const std::string & s)
{
	std::cout<<std::endl<<s;
}
// get data from file
void GetStrs(std::ifstream &, std::vector<std:: string> &);

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp; // acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
		// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	
	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
//	for_each(vistr.begin(), vistr.end(), ShowStr);
	return 0;
}

// Store function
void Store::operator () (const std::string &s)
{
	int len = s.size();
	out.write((char*)&len,sizeof(std::size_t));
	out.write(s.data(),len);
}

void GetStrs(std::ifstream & in, std::vector<std:: string> &vects)
{
	int len;
	while(in.read((char*)&len,sizeof(std::size_t)))
	{
		std::string temp;
		for(int i =0; i<len;i++)
		{
			char ch ;
			in.read((char*)&ch,sizeof(ch));
			temp.push_back(ch);	
		}
		vects.push_back(temp);
	}
}