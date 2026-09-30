#include <iostream>
using namespace std;


class LinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    ~LinkedList();

    void insertAtHead(int value);
    void insertAtTail(int value);
    bool deleteValue(int value);
    bool search(int value);
    int length();
    void reverse();
    void print();
};


LinkedList::~LinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
}


void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}


void LinkedList::insertAtTail(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}


bool LinkedList::deleteValue(int value) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }

        current = current->next;
    }

    return false;
}


bool LinkedList::search(int value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}


int LinkedList::length() {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}


void LinkedList::reverse() {
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}


void LinkedList::print() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "null" << endl;
}


int main() {
    LinkedList L;

    L.insertAtHead(30);
    L.insertAtHead(20);
    L.insertAtHead(10);
    cout << "TC1: ";
    L.print();

    L.insertAtTail(40);
    L.insertAtTail(50);
    cout << "TC2: ";
    L.print();

    cout << "TC3: length = " << L.length() << endl;

    cout << "TC4: search(30)=" << L.search(30)
         << " search(99)=" << L.search(99) << endl;

    L.deleteValue(10);
    cout << "TC5: ";
    L.print();

    L.deleteValue(50);
    cout << "TC6: ";
    L.print();

    L.deleteValue(30);
    cout << "TC7: ";
    L.print();

    bool r = L.deleteValue(99);
    cout << "TC8: deleteValue(99)=" << r << endl;

    LinkedList L2;
    L2.insertAtTail(1);
    L2.insertAtTail(2);
    L2.insertAtTail(3);
    L2.reverse();

    cout << "TC9: ";
    L2.print();

    LinkedList L3;
    cout << "TC10: length=" << L3.length()
         << " search=" << L3.search(5)
         << " delete=" << L3.deleteValue(5) << endl;

    return 0;
}