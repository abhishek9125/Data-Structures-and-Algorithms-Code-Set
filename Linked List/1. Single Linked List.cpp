#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
    
        ~Node() {
            if(this->next != NULL) {
                this->next = NULL;
                delete next;
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

    tail->next = temp;
    return;
}

void insertAtPosition(Node*& head, int position, int data) {

    if(position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(temp && count < position - 1) {
        temp = temp->next;
        count++;
    }
    
    cout << endl;
    Node* node1 = new Node(data);
    
    node1->next = temp->next;
    temp->next = node1;
    
    return;
}

void deleteNode(Node*& head, int position) {

    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    int count = 1;

    while(count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    prev->next = current->next;
    current->next = NULL;
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

int main() {

    Node* head = NULL;
    // insertAtTail(head, 60);
    // insertAtTail(head, 70);
    insertAtHead(head, 40);
    // printList(head);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    // printList(head);
    insertAtHead(head, 10);
    printList(head);
    insertAtPosition(head, 3, 25);
    insertAtPosition(head, 6, 45);
    
    insertAtPosition(head, 1, 5);
    printList(head);
    deleteNode(head, 1);
    deleteNode(head, 3);
    deleteNode(head, 5);
    printList(head);

    return 0;
}
