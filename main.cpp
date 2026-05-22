// COMSC210 | Final Exam 2 | Loma Kim
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    string name, order;
    Node *next;
};

int main() {
    ifstream fin;
    const int N_SIZE = 50, C_SIZE = 15;
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

    return 0;
}