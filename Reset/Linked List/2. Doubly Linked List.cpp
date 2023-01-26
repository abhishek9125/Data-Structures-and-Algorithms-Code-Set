#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    
        ~Node() {
            if(this->next != NULL) {
                this->next = NULL;
                delete next;
            }

            if(this->prev != NULL) {
                this->prev = NULL;
                delete prev;
            }
        }
};

void insertAtHead(Node*& head, int data) {

    Node* temp = new Node(data);

    if(head == NULL) {
        head = temp;
        return;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;

    return;
}

void insertAtTail(Node*& head, int data) {

    Node* temp = new Node(data);

    if(head == NULL) {
        head = temp;
        return;
    }

    Node* tail = head;

    while(tail->next != NULL) {
        tail = tail->next;
    }

    temp->prev = tail;
    tail->next = temp;

    return;
}

void insertAtPosition(Node*& head, int position, int data) {

    Node* temp = new Node(data);

    if(head == NULL) {
        head = temp;
        return;
    }

    if(position == 1) {
        insertAtHead(head, data);
        return;
    }

    int count = 1;
    Node* track = head;

    while(count < position - 1) {
        track = track->next;
        count++;
    }

    if(track->next == NULL) {
        insertAtTail(head, data);
    }

    track->next->prev = temp;
    temp->next = track->next;
    temp->prev = track;
    track->next = temp;

    return;
}

void deleteNode(Node*& head, int position) {

    Node* temp = head;

    if(position == 1) {
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;
    }

    int count = 1;

    while(count < position) {
        temp = temp->next;
        count++;
    }

    Node* current = temp;
    current = current->next;

    current->next->prev = temp;
    temp->next = current->next;

    current->next = NULL;
    current->prev = NULL;
    delete current;
    return;
}

void printList(Node*& head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

int getLen(Node* head) {

    int length = 0;
    Node* temp = head;

    while(temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

int main() {

    Node* node1 = new Node(10);

    return 0;
}
