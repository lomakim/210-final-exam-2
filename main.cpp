// COMSC210 | Final Exam 2 | Loma Kim
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    string name, order;
    Node *next;
};

int main() {
    srand(time(0));
    ifstream fin;
    const int N_SIZE = 50, C_SIZE = 15;
    int tempN;
    string tempS;
    string names[N_SIZE];
    string coffees[C_SIZE];
    Node *head = nullptr;

    //READ NAMES INTO ARRAY FROM FILE
    fin.open("names.txt");
    for (int i = 0; i < N_SIZE; i++) {
        getline(fin, tempS);
        names[i] = tempS;
        cout << names[i] << endl;
    }
    fin.close();

    //READ COFFEE ORDERS INTO ARRAY FROM FILE
    fin.open("coffee-orders.txt");
    for (int i = 0; i < C_SIZE; i++) {
        getline(fin, tempS);
        coffees[i] = tempS;
        cout << coffees[i] << endl;
    }
    fin.close();

    //INITIALIZE QUEUE
    for (int i = 0; i < 3; i++) {
        Node *newCust = new Node;

        if(!head) {
            head = newCust;
            newCust->next = nullptr;
            tempN = (rand() % N_SIZE) + 1;
            newCust->name = names[tempN - 1];
            tempN = (rand() % C_SIZE) + 1;
            newCust->order = coffees[tempN - 1];
        }
    }
    

    return 0;
}