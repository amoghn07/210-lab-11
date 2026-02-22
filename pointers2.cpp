#include <iostream>
#include <string>
using namespace std;


//Program tracks the number of items within each customer's bank vault.

struct Vault{
    string name;
    int nrItems;
    string *items = new string [nrItems];
    //destructor for items
    ~Vault(){
        if (items)
            delete [] items;
        items = nullptr;
    }
};

void inputUser(Vault *);
void displayVaults(Vault *);

int main(){
    int numVaults;
    cout << "Enter amount of vaults actively in use: ";
    cin >> numVaults;
    //dynamic array for Vault objects
    Vault *roster = new Vault[numVaults];

    for (int i = 0; i < numVaults; i++){
        inputUser(&roster[i]);
    }

    for (int i = 0; i < numVaults; i++){
        displayVaults(&roster[i]);
    }

    delete [] roster;

    return 0;

}

void inputUser(Vault *cptr){
    static int nrCust = 1;
    //int nrItems; 
    cout << "Enter data for Customer #" << nrCust << ": \n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, cptr -> name);
    cout << "Number of items in vault: ";
    cin >> cptr -> nrItems;

    //cptr -> items = new string[cptr -> nrItems];
    cin.ignore();
    for (int i = 0; i < cptr -> nrItems; i++){
        cout << "Enter Item #" << i + 1 << ": ";
        getline(cin, cptr -> items[i]);
    }
    cout << endl;
    nrCust++;
}

void displayVaults(Vault *cptr) {
    static int count = 1;
    cout << "Customer #" << count << " summary:\n";
    cout << "Name: " << cptr -> name << endl;
    for (int i = 0; i < cptr -> nrItems; i++)
        cout << "Item #" << i + 1 << ": " 
             << cptr -> items[i] << endl;
    cout << endl;
} 

