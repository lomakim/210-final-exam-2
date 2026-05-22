// COMSC210 | Final Exam 2 | Loma Kim
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
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
            }
            cout << temp->name << " is served their " 
                 << temp->order << ". " << endl;
            delete temp;
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
        cout << newNode->name << " has joined the line." << endl;
    }

    void print() {
    Node* current = head;
    cout << "\tResulting Line: " << endl;
    if (!current) {
        cout << "\t\tLine is empty." << endl << endl;
        return;
    }
    while (current) {
        cout << "\t\t" << current->name << endl;
        current = current->next;
    }
    cout << endl;
}
};

int main() {
    srand(time(0));
    ifstream fin;
    const int N_SIZE = 50, C_SIZE = 15, B_SIZE = 5;
    int tempN, prob;
    string tempS, tempS2;
    string names[N_SIZE];
    string coffees[C_SIZE];
    deque<string> muffinQueue;
    string muffins[C_SIZE] = { "blueberry", "poppy seed", "bran", 
                               "banana walnut", "carrot", "strawberry",
                               "chocolate chip", "double chocolate",
                               "pumpkin spice", "peanut butter", "plain",
                               "cinnamon", "zucchini", "lemon", "raspberry"};
    vector<string> braceletQueue;
    string bracelets[B_SIZE] = {"blue", "green", "pink", "red", "black"};
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

    //INITIALIZE QUEUES
    cout << "Starting Queues: " << endl;

    //COFFEE
    cout << "\nCoffee Queue:" << endl;
    for (int i = 0; i < 3; i++) {
        tempN = rand() % N_SIZE;
        tempS = names[tempN];
        tempN = rand() % C_SIZE;
        tempS2 = coffees[tempN];
        cout << "\t";
        coffeeQueue.push_back(tempS, tempS2);
    }

    //MUFFIN
    cout << "\nMuffin Queue" << endl;
    for (int i = 0; i < 3; i++) {
        tempN = rand() % N_SIZE;
        tempS = names[tempN];
        muffinQueue.push_back(tempS);
        cout << "\t" << tempS << " has joined the line." << endl;
    }

    //BRACELET
    cout << "\n\nFriendship Bracelet Queue: " << endl;
    for (int i = 0; i < 3; i++) {
        tempN = rand() % N_SIZE;
        tempS = names[tempN];
        braceletQueue.push_back(tempS);
        cout << "\t" << tempS << " has joined the line." << endl;
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Round " << i + 1 << ": " << endl; 
        prob = (rand() % 100) + 1;
        cout << "\tCoffee Queue: ";
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
        coffeeQueue.print();

        prob = (rand() % 100) + 1;
        cout << "\tMuffin Queue: ";
        if (prob <= 50) {
            if (muffinQueue.empty()) {
                cout << "Line is empty." << endl;
            }
            else {
            tempN = rand() % C_SIZE;
            cout << muffinQueue[0] << " has been served their "
                 << muffins[tempN] << " muffin." << endl;
            muffinQueue.pop_front();
            }
        }
        else {
            tempN = rand() % N_SIZE;
            tempS = names[tempN];
            muffinQueue.push_back(tempS);
            cout << tempS << " has joined the line" << endl;
        }
        cout << "\tResulting Line: " << endl;
        if(muffinQueue.empty()) {
            cout << "Line is empty." << endl;
        }
        else {
            for (int i = 0; i < muffinQueue.size(); i++) {
                cout << "\t\t" << muffinQueue[i] << endl;
            }
        }

        prob = (rand() % 100) + 1;
        cout << "\n\tBracelet Queue: ";
        if (prob <= 50) {
            if (braceletQueue.empty()) {
                cout << "\t\tLine is empty." << endl;
            }
            else {
            tempN = rand() % B_SIZE;
            cout << braceletQueue[0] << " has purchased their "
                 << bracelets[tempN] << " bracelet." << endl;
            braceletQueue.erase(braceletQueue.begin());
            }
        }
        else {
            tempN = rand() % N_SIZE;
            tempS = names[tempN];
            braceletQueue.push_back(tempS);
            cout << tempS << " has joined the line" << endl;
        }
        cout << "\tResulting Line: " << endl;
        if(braceletQueue.empty()) {
            cout << "\t\tLine is empty." << endl;
        }
        else {
            for (int i = 0; i < braceletQueue.size(); i++) {
                cout << "\t\t" << braceletQueue[i] << endl;
            }
        }
    }

    return 0;
}