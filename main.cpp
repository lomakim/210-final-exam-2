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
    string names[N_SIZE];
    string coffees[C_SIZE];
    Node *head = nullptr;

    fin.open("names.txt");
    while(fin)
    
    return 0;
}