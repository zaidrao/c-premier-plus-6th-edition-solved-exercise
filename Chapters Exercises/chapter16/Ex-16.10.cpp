#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
	std::string title;
	int rating;
	int price;
};
typedef  std::shared_ptr<Review> pr;
typedef  std::vector<pr> vsp;
bool operator<(const pr &r1, const pr &r2);
bool worseThan(const pr &r1, const pr &r2);
bool byPrice(const pr &r1, const pr &r2);
bool FillReview(pr &rr);
void ShowReview(const pr &rr);

int main()
{
	using namespace std;
	vector<shared_ptr<Review>> books;
	char choice;
	
	while (true)
	{
		shared_ptr<Review> temp(new Review);
		if(FillReview(temp))
		books.push_back(temp);
		else
		break;
	}
	vsp alphSort = books;
	// alphabetical sort
	sort(alphSort.begin(),alphSort.end());
	
	vsp byInRating = books;
	// sort by increase rating
	sort(byInRating.begin(),byInRating.end(), worseThan);
	
	vsp byDecRating = byInRating;
	// sort by decrease rating
	copy(byInRating.rbegin(),byInRating.rend(),byDecRating.begin());
	
	vsp byInPrice = books;
	// sort by increase price
	sort(byInPrice.begin(),byInPrice.end(),byPrice);
	
	vsp byDecPrice = books ;
	// sort by decrease rating
	copy(byInPrice.rbegin(),byInPrice.rend(),byDecPrice.begin());

	cout<<"----Showing----";
	cout<<"\n1: By Alphabetically Order \n2: By Original Order \n3: By increasing ratings \n4: By decreasing ratings \n5: By increasing price \n6: By decreasing price \n7: Quite"<<endl;
	cout<<"Enter choice: ";
	while ((cin>>choice) && (choice != '7') )
	{
		switch (choice)
		{
		case '1':
		cout<<"Alphabetical order"<<endl;
		for_each(alphSort.begin(),alphSort.end(),ShowReview);
		break;
		case '2':
		cout<<"Original order"<<endl;
		for_each(books.begin(),books.end(),ShowReview);
		break;
		case '3':
		cout<<"Increasing Ratings order"<<endl;
		for_each(byInRating.begin(),byInRating.end(),ShowReview);
		break;
		case '4':
		cout<<"Decreasing Ratings order"<<endl;
		for_each(byDecRating.begin(),byDecRating.end(),ShowReview);
		break;
		case '5':
		cout<<"Increasing Prices order"<<endl;
		for_each(byInPrice.begin(),byInPrice.end(),ShowReview);
		break;
		case '6':
		cout<<"Decreasing Prices order"<<endl;
		for_each(byDecPrice.begin(),byDecPrice.end(),ShowReview);
		break;
		case '7':
		break;
		default:
		cout<<"\nEnter valid."<<endl;
		break;
		}
		cout<<"Enter again: ";
	}
	cout << "Bye.\n";
	return 0;
}
bool operator<(const pr &r1, const pr &r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
		return true;
	else
		return false;
}

bool worseThan(const pr &r1, const pr &r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}
bool byPrice(const pr &r1, const pr &r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}

bool FillReview(pr &rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr->title);
	if (rr->title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr->rating;
	std::cout << "Enter book price: ";
	std::cin >> rr->price;
	if (!std::cin)
		return false;
		// get rid of rest of input line
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const pr &rr)
{
	std::cout << rr->rating << "\t" << rr->title <<"\t"<<rr->price<< std::endl;
}