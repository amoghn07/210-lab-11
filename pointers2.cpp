#include <iostream>
#include <string>
using namespace std;


//Program tracks the number of items within each customer's bank vault.

struct Vault{
    string name;
    int *items;
    //destructor for items
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
    cout << "Enter amount of vaults actively in use: ";
    cin >> numVaults;
    //dynamic array for Vault objects
    Vault *roster = new Vault[numVaults];

    for (int i = 0; i < numVaults; i++){
        inputUser(&roster[i]);
    }

    return 0;

}

void inputUser(Vault *cptr){
    static int nrCust = 1;
    int nrItems; 
    cout << "Enter data for Customer #" << nrCust << ": \n";
    cout << "Name: ";
    getline(cin, cptr -> name);
    cout << "Number of items in vault: ";
    cin >> nrItems;
    
    for (int i = 0; i < nrItems; i++){
        cout << "Enter Item #" << i + 1 << ": ";
        cptr -> items[i];
    }
}

