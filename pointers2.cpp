#include <iostream>
#include <string>
using namespace std;


//Program tracks the number of items within each customer's bank vault.

struct Vault{
    string name;
    int *items;

    ~Vault(){
        if (items)
            delete [] items;
        items = nullptr;
    }
};

void inputUser(Vault *);
void outputStudent(Vault *);

int main(){
    int numVaults;
    Vault *roster;
    cout << "Enter amount of vaults actively in use: ";
    cin >> numVaults;

    for (int i = 0; i < numVaults; i++){

    }

}

