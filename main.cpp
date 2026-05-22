// COMSC210 | Final Exam 2 | Loma Kim
#include <iostream>
#include <fstream>
using namespace std;

class LinkedList {
    private:
    struct Node {
        string name, order;
        Node* next;
        Node* prev;
        Node(string n, string o) {
            name = n;
            order = o;
            prev = next = nullptr;
        }
    };
    Node* head;
    Node* tail;

    public: 
    LinkedList() { head = tail = nullptr;}

    void pop_front() {
        if(!head) {
            cout << "Line is empty.";
            return;
        }
        Node* temp = head;
        if(head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else {
            head = tail = nullptr;
            cout << temp->name << " is served their " 
                 << temp->order << ". " << endl;
            delete temp;
        }
    }

    void push_back(string n, string o) {
        Node* newNode = new Node(n, o);
        if(!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << newNode->name << " has joined the line." << endl;
    }

    void print() {
    Node* current = head;
    cout << "\nResulting Line: " << endl;
    if (!current) {
        cout << "\tLine is empty." << endl;
        return;
    }
    while (current) {
        cout << "\t" << current->name << endl;
        current = current->next;
    }
    cout << endl;
}
};

int main() {
    srand(time(0));
    ifstream fin;
    const int N_SIZE = 50, C_SIZE = 15;
    int tempN;
    string tempS, tempS2;
    string names[N_SIZE];
    string coffees[C_SIZE];
    LinkedList coffeeQueue;

    //READ NAMES INTO ARRAY FROM FILE
    fin.open("names.txt");
    for (int i = 0; i < N_SIZE; i++) {
        getline(fin, tempS);
        names[i] = tempS;
    }
    fin.close();

    //READ COFFEE ORDERS INTO ARRAY FROM FILE
    fin.open("coffee-orders.txt");
    for (int i = 0; i < C_SIZE; i++) {
        getline(fin, tempS);
        coffees[i] = tempS;
    }
    fin.close();

    //INITIALIZE QUEUE
    for (int i = 0; i < 3; i++) {
        tempN = rand() % N_SIZE;
        tempS = names[tempN];
        tempN = rand() % C_SIZE;
        tempS2 = coffees[tempN];
        coffeeQueue.push_back(tempS, tempS2);
    }
    coffeeQueue.print();
    

    return 0;
}