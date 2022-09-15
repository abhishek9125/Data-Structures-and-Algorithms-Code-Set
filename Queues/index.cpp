#include <iostream>
using namespace std;

class Queue {
    
    int* arr;
    int qFront;
    int rear;
    int size;
    
public:
    Queue() {
        size = 10001;
        arr = new int[size];
        qFront = 0;
        rear = 0;
    }

    // Time Complexity : O(1) for all operations
    bool isEmpty() {
        return qFront == rear;
    }

    void enqueue(int data) {
        if(rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear++] = data;
        }
    }

    int dequeue() {
        if(qFront == rear) {
            return -1;
        } else {
            int ans = arr[qFront];
            
            arr[qFront++] = -1;
            if(qFront == rear) {
                qFront = rear = 0;
            }
            
            return ans;
        }
    }

    int front() {
        if(qFront == rear) {
            return -1;
        } else {
            return arr[qFront];
        }
    }
};

int main() {

    Queue q;

    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.dequeue();
    return 0;
}