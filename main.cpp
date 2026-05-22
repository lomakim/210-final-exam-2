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

        else {
            Node* temp = head;
            if(head->next) {
                head = head->next;
                head->prev = nullptr;
            }
            else {
                head = tail = nullptr;
                cout << "\t" << temp->name << " is served their " 
                    << temp->order << ". " << endl;
                delete temp;
            }
        }
    }

    void push_back(string n, string o) {
        Node* newNode = new Node(n, o);
        if(!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "\t" << newNode->name << " has joined the line." << endl;
    }

    void print() {
    Node* current = head;
    cout << "\n\tResulting Line: ";
    if (!current) {
        cout << "Line is empty." << endl;
        return;
    }
    while (current) {
        cout << "\n\t\t" << current->name << endl;
        current = current->next;
    }
    cout << endl;
}
};

int main() {
    srand(time(0));
    ifstream fin;
    const int N_SIZE = 50, C_SIZE = 15;
    int tempN, prob;
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
    cout << "Starting line: " << endl;
    for (int i = 0; i < 3; i++) {
        tempN = rand() % N_SIZE;
        tempS = names[tempN];
        tempN = rand() % C_SIZE;
        tempS2 = coffees[tempN];
        coffeeQueue.push_back(tempS, tempS2);
    }
    for (int i = 0; i < 10; i++){
        cout << "Round # " << i + 1 << ": " << endl; 
        prob = (rand() % 100) + 1;
        if (prob <= 50) {
            tempN = rand() % N_SIZE;
            tempS = names[tempN];
            tempN = rand() % C_SIZE;
            tempS2 = coffees[tempN];
            coffeeQueue.push_back(tempS, tempS2);
        } 
        else {
            coffeeQueue.pop_front();
        }
    }

    

    return 0;
}