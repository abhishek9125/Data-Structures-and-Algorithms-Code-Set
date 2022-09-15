#include <iostream>
using namespace std;

class CircularQueue{
    public:

    int* arr;
    int front;
    int rear;
    int size;
    
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool enqueue(int value){
        
        if((front == 0 && rear == size - 1) || (rear == front - 1)) {
            return false;
        } else if(front == -1) {
            front = rear = 0;
        } else if(rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        
        arr[rear] = value;
        return true;
        
    }

    int dequeue(){
        if(front == -1) {
            return -1;
        }  
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) {
            front = -1;
            rear = -1;
        } else if(front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        
        return ans;
        
    }
};
int main() {

    CircularQueue q(5);

    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.dequeue();
    return 0;
}