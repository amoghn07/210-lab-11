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

