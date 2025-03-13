#include <iostream>
#include <string>
using namespace std;

class SinglyLinkedList {
    public:
    string data;
    SinglyLinkedList* next;
    SinglyLinkedList(string data): data(data), next(nullptr) {};
};

class List {
    private:
    SinglyLinkedList* head;
    public:
    List(): head(nullptr) {};

    void pushStack(string data) {
        SinglyLinkedList* temp = new SinglyLinkedList(data);
        temp->next = head;
        head = temp;
    }

    void pushQueue(string data) {
        if (head == nullptr) {
            head = new SinglyLinkedList(data);
        }
        else {
            SinglyLinkedList* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new SinglyLinkedList(data);
        }
    }
    void print() {
        SinglyLinkedList* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void deletElement(string key) {
        if (!head) {
            cout << "List is empty";
            return;
        }
        SinglyLinkedList* temp = head;
        while (temp->next != nullptr and temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Element not found" << endl;
            return;
        }
        SinglyLinkedList* deleter = temp->next;
        temp->next = temp->next->next;
        delete deleter;
    }
    void addElem(string key, string data) {
        if (!head) {
            cout << "List is empty";
            return;
        }
        SinglyLinkedList* temp = head;
        while (temp != nullptr and temp->data != key) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Element not found" << endl;
            return;
        }
        SinglyLinkedList* adder = new SinglyLinkedList(data);
        adder->next = temp->next;
        temp->next = adder;
    }
    ~List() {
        while (head) {
            SinglyLinkedList* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    List a;
    for (int i{1}; i < 11; i++) {
        a.pushQueue(to_string(i));
    }
    a.print();
    a.pushStack("0");
    a.print();
    a.deletElement("8");
    a.deletElement("10");
    a.print();
    a.deletElement("10");
    a.addElem("8", "9");
    a.addElem("9", "10");
    a.print();
}
