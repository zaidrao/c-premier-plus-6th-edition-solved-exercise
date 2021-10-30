#include <iostream>
#include <new>
#include <cstring>

using namespace std;

const int BUF_SIZE = 512;
const int LEN = 20;

char buffer[BUF_SIZE];

struct chaff {
char dross[LEN];
int slag;
};

int main() {
int choice = 0;
chaff *chaffs;


while (choice != 1 && choice != 2) {
cout << "How to allocate array? Enter 1 for static array, 2 for regular new: ";
cin >> choice;
}

if (choice == 1) {
chaffs = new (buffer) chaff[2];
} else {
chaffs = new chaff[2];
}

strcpy(chaffs[0].dross, "Dross 1");
strcpy(chaffs[1].dross, "Dross 2");

chaffs[0].slag = 1;
chaffs[1].slag = 2;

for (int i = 0; i < 2; i++) {
cout << "Chaff #" << i + 1 << endl;
cout << "dross: " << chaffs[i].dross << ", slag: " << chaffs[i].slag <<  endl;
}

if (choice == 2) {
delete [] chaffs;
}

return 0;
}