#include <iostream>
using namespace std;

// Stack -> Linked List

class Stack
{
    int size;
    int *arr;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Memory Overflow" << endl;
            return;
        }

        top++;
        arr[top] = data;
        return;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        arr[top--] = -1;
    }

    int top()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{

    return 0;
}
