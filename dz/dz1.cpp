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


}