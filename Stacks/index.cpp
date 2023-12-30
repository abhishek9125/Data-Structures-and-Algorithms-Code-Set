#include <iostream>
using namespace std;

class Stack {
    publix:
        int* arr;
        int top;
        int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int top() {
        if(top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

};

int main() {
    cout<<"Hello World!";
}
